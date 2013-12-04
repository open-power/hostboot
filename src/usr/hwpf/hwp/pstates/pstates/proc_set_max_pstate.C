/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/proc_set_max_pstate.C $      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2013,2014                        */
/* [+] Google Inc.                                                        */
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
/// \file proc_set_max_pstate.C
//------------------------------------------------------------------------------

// ----------------------------------------------------------------------
// Includes
// ----------------------------------------------------------------------
#include <fapi.H>

#include "ecmdDataBufferBase.H"
#include "pstate_tables.h"
#include "lab_pstates.h"
#include "pstates.h"

#include "proc_get_voltage.H"
#include "p8_scom_addresses.H"

extern "C" {

fapi::ReturnCode proc_set_max_pstate(const fapi::Target& i_proc_target)
{
    fapi::ReturnCode     l_rc;
    uint32_t             i = 0;
    PstateSuperStructure pss;
    gpst_entry_t         entry;
    Pstate               pnom              = 0;
    uint8_t              freq_pstate_index = 0;
    uint64_t             freq_nom_khz      = 0;
    uint32_t             vdd               = 0;
    uint32_t             vcs               = 0;
    std::vector<fapi::Target>       l_exChiplets;
    std::vector<fapi::Target>       l_coreChiplets;

    // Create pstate super structure
    FAPI_ERR("Executing proc_set_max_pstate");

    FAPI_EXEC_HWP(l_rc,  p8_build_pstate_datablock, i_proc_target,  &pss);
    if (!l_rc.ok()) {
        FAPI_ERR("Error calling p8_build_pstate_datablock");
        return l_rc;
    }

    // Get nominal frequency.
    uint32_t sys_freq_nom = 0;
    l_rc = FAPI_ATTR_GET(ATTR_FREQ_CORE_NOMINAL, NULL, sys_freq_nom);
    if (l_rc) { return l_rc; }
    sys_freq_nom *= 1000; // Convert to khz.

    // Get the pstate closest to nominal frequency.
    if (freq2pState(&pss.gpst, sys_freq_nom, &pnom))
    {
        // Failed to find a frequency.  Use pmin.
        FAPI_ERR("Unable to find a frequency closest to nominal.  Using pmin.");
        pnom = gpst_pmin(&pss.gpst);
    }

    freq_nom_khz = (pss.gpst.pstate0_frequency_khz +
            pss.gpst.frequency_step_khz * pnom);

    // Convert pstate to pstate table index and lookup voltages
    freq_pstate_index = pnom - pss.gpst.pmin;
    entry.value = revle64(pss.gpst.pstate[freq_pstate_index].value);
    vdd = entry.fields.evid_vdd;
    vcs = entry.fields.evid_vcs;

    FAPI_INF("%s nominal pstate is %d, freq: %dKhz VDD: %dmV VCS: %dmV",
            i_proc_target.toEcmdString(), pnom, freq_nom_khz,
            VRM11_BASE_UV - 6250 * vdd, VRM11_BASE_UV - 6250 * vcs);

    // Set the voltage.
    ecmdDataBufferBase wdata_reg(64);
    wdata_reg.setByte(0, 0);
    wdata_reg.setByte(1, vdd);
    wdata_reg.setByte(2, vcs);
    wdata_reg.setByte(3, 0);
    l_rc = fapiPutScom(i_proc_target, PMC_O2S_WDATA_REG_0x00062058, wdata_reg);
    if (l_rc)
    {
        FAPI_ERR("SCOM to PMC_O2S_WDATA_REG_0x00062058 failed.");
        return l_rc;
    }
    // Wait for voltage ramp.
    fapiDelay(1e8, 0);

    // Set the frequency on each EX.
    l_rc = fapiGetChildChiplets (i_proc_target, fapi::TARGET_TYPE_EX_CHIPLET,
            l_exChiplets, fapi::TARGET_STATE_FUNCTIONAL);
    if (l_rc)
    {
        FAPI_ERR("Error from fapiGetChildChiplets!");
        return l_rc;
    }

    for (i = 0; i < l_exChiplets.size(); i++)
    {
        uint8_t l_chipNum = 0xFF;
        l_rc = FAPI_ATTR_GET(ATTR_CHIP_UNIT_POS, &l_exChiplets[i], l_chipNum);
        if (l_rc)
        {
            FAPI_ERR("fapiGetAttribute of ATTR_CHIP_UNIT_POS error");
            return l_rc;
        }

        ecmdDataBufferBase freqcntl_reg(64);
        l_rc = fapiGetScom(i_proc_target,
                EX_FREQCNTL_0x100F0151 + (l_chipNum * 0x01000000),
                freqcntl_reg);
        if (l_rc)
        {
            return l_rc;
        }

        // Set frequency multiplier based on ref clock.
        uint32_t mult = freq_nom_khz / 1000 / 33;
        freqcntl_reg.insertFromRight(&mult, 0, 9);
        freqcntl_reg.insertFromRight(&mult, 9, 9);

        FAPI_ERR("%s setting to multiplier %dX",
                l_exChiplets[i].toEcmdString(),
                mult);
        l_rc = fapiPutScom(i_proc_target,
                EX_FREQCNTL_0x100F0151 + (l_chipNum * 0x01000000),
                freqcntl_reg);
        if (l_rc)
        {
            return l_rc;
        }

        unsigned int freq_mhz = freq_nom_khz / 1000;
        l_rc = FAPI_ATTR_SET(ATTR_FREQ_CORE, &l_exChiplets[i], freq_mhz);
        if (l_rc)
        {
            return l_rc;
        }
    }

    return l_rc;
}

} //end extern C

