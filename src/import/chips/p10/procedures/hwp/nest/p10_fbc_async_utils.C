/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/import/chips/p10/procedures/hwp/nest/p10_fbc_async_utils.C $ */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2021                             */
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
/// @file p10_fbc_async_utils.C
/// @brief Fabric async boundary crossing utility functions (FAPI2)
///
/// *HWP HW Maintainer: Joe McGill <jmcgill@us.ibm.com>
/// *HWP FW Maintainer: Ilya Smirnov <ismirno@us.ibm.com>
/// *HWP Consumed by: HB
///
// EKB-Mirror-To: hostboot

//------------------------------------------------------------------------------
// Includes
//------------------------------------------------------------------------------
#include <p10_fbc_async_utils.H>
#include <p10_fbc_utils.H>
#include <p10_scom_perv.H>


fapi2::ReturnCode
p10_fbc_async_utils_calc_pau_ratios(
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    rt2pa_ratio& o_rt2pa,
    pa2rt_ratio& o_pa2rt)
{
    FAPI_DBG("Start");

    // RT2PA
    // RT->PAU NOMINAL when Nest Fmin >= 1/2 * Fpau
    // RT->PAU SAFE    when Nest Fmin <  1/2 * Fpau
    //
    // PA2RT
    // PAU->RT TURBO   when Fpau >= 4/2 * Nest Fmax
    // PAU->RT NOMINAL when Fpau >= 3/2 * Nest Fmax and Fpau < 4/2 * Nest Fmax
    // PAU->RT SAFE    when                             Fpau < 3/2 * Nest Fmax
    //

    // read platform frequency attributes
    fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_Type l_core_fmin;
    fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_Type l_core_fmax;
    fapi2::ATTR_FREQ_PAU_MHZ_Type l_fpau;

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_PAU_MHZ,
                           i_target_sys,
                           l_fpau));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ,
                           i_target_sys,
                           l_core_fmin));

    FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ,
                           i_target_sys,
                           l_core_fmax));

    // calculate modes
    // racetrack-to-PAU
    if (l_core_fmin >= l_fpau)
    {
        o_rt2pa = RT2PA_RATIO_NOMINAL;
        FAPI_DBG("  RT2PA: N");
    }
    else
    {
        o_rt2pa = RT2PA_RATIO_SAFE;
        FAPI_DBG("  RT2PA: S");
    }

    // PAU-to-racetrack
    if (l_fpau >= l_core_fmax)
    {
        o_pa2rt = PA2RT_RATIO_TURBO;
        FAPI_DBG("  PA2RT: T");
    }
    else if ((4 * l_fpau) >= (3 * l_core_fmax))
    {
        o_pa2rt = PA2RT_RATIO_NOMINAL;
        FAPI_DBG("  PA2RT: N");
    }
    else
    {
        o_pa2rt = PA2RT_RATIO_SAFE;
        FAPI_DBG("  PA2RT: S");
    }

fapi_try_exit:
    FAPI_DBG("OUTPUT pau_freq: %d, rt2pa: %d, pa2rt: %d",
             l_fpau,
             o_rt2pa,
             o_pa2rt);
    FAPI_DBG("End");
    return fapi2::current_err;
}



fapi2::ReturnCode
p10_fbc_async_utils_calc_mc_ratios(
    const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>& i_target_proc,
    const fapi2::Target<fapi2::TARGET_TYPE_SYSTEM>& i_target_sys,
    uint32_t& o_mc_freq_mhz,
    rt2mc_ratio& o_rt2mc,
    mc2rt_ratio& o_mc2rt)
{
    FAPI_DBG("Start");

    fapi2::ATTR_FREQ_MC_MHZ_Type l_fmc;
    bool l_fmc_valid = false;
    char l_targetStr[fapi2::MAX_ECMD_STRING_LEN];
    fapi2::toString(i_target_proc, l_targetStr, fapi2::MAX_ECMD_STRING_LEN);

    // set defaults assuming no MC on chip to configure most aggressive
    // settings.  presence of any MC on chip will align to appopriate
    // values
    o_mc_freq_mhz = 2000; // DDR5
    o_rt2mc = RT2MC_RATIO_ULTRATURBO;
    o_mc2rt = MC2RT_RATIO_ULTRATURBO;

    FAPI_DBG("Target: %s",
             l_targetStr);

    FAPI_DBG("DEFAULT mc_freq: %d, rt2mc: %d, mc2rt: %d",
             o_mc_freq_mhz,
             o_rt2mc,
             o_mc2rt);

    // current code supports only one common MC frequency across a given
    // chip, confirm attribute state reflects this
    {
        fapi2::ATTR_FREQ_MC_MHZ_Type l_fmc_common;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_mc_pos_common;
        fapi2::ATTR_CHIP_UNIT_POS_Type l_mc_pos;

        for (auto& l_mc_target : i_target_proc.getChildren<fapi2::TARGET_TYPE_MC>())
        {
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_CHIP_UNIT_POS, l_mc_target, l_mc_pos),
                     "Error from FAPI_ATTR_GET (ATTR_CHIP_UNIT_POS_Type)");
            FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_MC_MHZ, l_mc_target, l_fmc),
                     "Error from FAPI_ATTR_GET (ATTR_FREQ_MC_MHZ)");

            if (!l_fmc_valid)
            {
                l_fmc_common = l_fmc;
                l_mc_pos_common = l_mc_pos;
                l_fmc_valid = true;
                FAPI_DBG("Found valid MC, unit pos: %d, freq: %d",
                         l_mc_pos_common, l_fmc_common);
            }

            FAPI_ASSERT(l_fmc_common == l_fmc,
                        fapi2::P10_BOOT_MODE_UNEQUAL_MC_FREQS()
                        .set_CHIP_TARGET(i_target_proc)
                        .set_MC_UNIT1(l_mc_pos_common)
                        .set_MC_FREQ1(l_fmc_common)
                        .set_MC_UNIT2(l_mc_pos)
                        .set_MC_FREQ2(l_fmc),
                        "Chip has unequal MC chiplet frequencies");
        }
    }

#ifdef __HOSTBOOT_MODULE

    // based on SW510588/113964, SBE will ensure one MC is always functional on the
    // primary/boot processor.  Hostboot unfortunately does not share the same view that the
    // MC is functional (based on relying on what FSP/BMC feeds into the SBE mailbox)
    // support this case by querying the actual chiplet enable state from the MC
    // chiplet PCB slave registers (always accessible), and querying the scratch
    // registers ourselves to determine the frequency the SBE has established for this MC
    if (!l_fmc_valid)
    {
        // Hostboot views no MC as functional, check HW state for each MC chiplet
        // to see if any really are active
        fapi2::buffer<uint64_t> l_net_ctrl0;

        for (uint8_t l_mc_chiplet_id = 0xC;                   // MC0
             (l_mc_chiplet_id <= 0xF) && !l_fmc_valid;        // MC3
             l_mc_chiplet_id++)
        {
            uint32_t l_net_ctrl0_addr = 0;
            l_net_ctrl0_addr = (l_mc_chiplet_id << 24) |
                               scomt::perv::NET_CTRL0_RW;
            FAPI_TRY(fapi2::getScom(i_target_proc,
                                    l_net_ctrl0_addr,
                                    l_net_ctrl0));

            // chiplet is enabled, need to determine its frequency
            // read scratch9 register
            if (l_net_ctrl0.getBit<scomt::perv::NET_CTRL0_CHIPLET_ENABLE>())
            {
                l_fmc_valid = true;
                fapi2::buffer<uint64_t> l_scratch9;
                uint8_t l_mc_pll_bucket = 0;
                FAPI_TRY(fapi2::getScom(i_target_proc,
                                        scomt::perv::FSXCOMP_FSXLOG_SCRATCH_REGISTER_9_RW,
                                        l_scratch9));
                // MC PLL bucket encoding starts at bit 16, 3 bits per chiplet
                // 16:18 = MC0
                // 19:21 = MC1
                // 22:24 = MC2
                // 25:27 = MC3
                FAPI_TRY(l_scratch9.extractToRight(l_mc_pll_bucket,
                                                   16 + (3 * (l_mc_chiplet_id - 0xC)),
                                                   3));

                switch (l_mc_pll_bucket)
                {
                    case 0:
                        l_fmc = 1600;
                        break;

                    case 1:
                        l_fmc = 1466;
                        break;

                    case 2:
                        l_fmc = 1333;
                        break;

                    case 4:
                        l_fmc = 2000;
                        break;

                    default:
                        l_fmc = 1333;
                        break;
                }
            }
        }
    }

#endif

    // RT2MC
    // RT->MC ULTRA_TURBO when Nest Fmin >= 3/2 * Fmc
    // RT->MC TURBO       when Nest Fmin >= 2/2 * Fmc and Nest Fmin < 3/2 * Fmc
    // RT->MC NOMINAL     when Nest Fmin >= 1/2 * Fmc and Nest Fmin < 2/2 * Fmc
    // RT->MC SAFE        when                            Nest Fmin < 1/2 * Fmc
    //
    // MC2RT
    // MC->RT ULTRA_TURBO when Fmc >= 4/2 * Nest Fmax
    // MC->RT TURBO when       Fmc >= 3/2 * Nest Fmax and Fmc < 4/2 * Nest Fmax
    // MC->RT NOMINAL when     Fmc >= 2/2 * Nest Fmax and Fmc < 3/2 * Nest Fmax
    // MC->RT SAFE when                                   Fmc < 2/2 * Nest Fmax

    if (l_fmc_valid)
    {
        // read platform frequency attributes
        fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ_Type l_core_fmin;
        fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ_Type l_core_fmax;

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_FLOOR_MHZ,
                               i_target_sys,
                               l_core_fmin));

        FAPI_TRY(FAPI_ATTR_GET(fapi2::ATTR_FREQ_SYSTEM_CORE_CEILING_MHZ,
                               i_target_sys,
                               l_core_fmax));

        // grid frequency
        o_mc_freq_mhz = l_fmc;
        FAPI_DBG("  GRID: %d", l_fmc);

        // racetrack-to-MC
        if (l_core_fmin >= (3 * l_fmc))
        {
            o_rt2mc = RT2MC_RATIO_ULTRATURBO;
            FAPI_DBG("  RT2MC: UT");
        }
        else if (l_core_fmin >= (2 * l_fmc))
        {
            o_rt2mc = RT2MC_RATIO_TURBO;
            FAPI_DBG("  RT2MC: T");
        }
        else if (l_core_fmin >= l_fmc)
        {
            o_rt2mc = RT2MC_RATIO_NOMINAL;
            FAPI_DBG("  RT2MC: N");
        }
        else
        {
            o_rt2mc = RT2MC_RATIO_SAFE;
            FAPI_DBG("  RT2MC: S");
        }

        // MC-to-racetrack
        if (l_fmc >= l_core_fmax)
        {
            o_mc2rt = MC2RT_RATIO_ULTRATURBO;
            FAPI_DBG("  MC2RT: UT");
        }
        else if ((4 * l_fmc) >= (3 * l_core_fmax))
        {
            o_mc2rt = MC2RT_RATIO_TURBO;
            FAPI_DBG("  MC2RT: T");
        }
        else if ((2 * l_fmc) >= l_core_fmax)
        {
            o_mc2rt = MC2RT_RATIO_NOMINAL;
            FAPI_DBG("  MC2RT: N");
        }
        else
        {
            o_mc2rt = MC2RT_RATIO_SAFE;
            FAPI_DBG("  MC2RT: S");
        }
    }

fapi_try_exit:
    FAPI_DBG("OUTPUT mc_freq: %d, rt2mc: %d, mc2rt: %d",
             o_mc_freq_mhz,
             o_rt2mc,
             o_mc2rt);
    FAPI_DBG("End");

    return fapi2::current_err;
}
