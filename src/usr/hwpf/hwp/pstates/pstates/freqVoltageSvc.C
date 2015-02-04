/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/pstates/pstates/freqVoltageSvc.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
/**
 *  @file freqVoltageSvc.C
 *
 *  @brief Contains freqVoltage class definition
 *
 *  This file contains implementation of frequency voltage service class. This
 *  class is used for reading/parsing/writing frequency and voltage related
 *  data.
 *
 */

#include <stdio.h>

#include <freqVoltageSvc.H>

#include <devicefw/userif.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <fapiPlatHwpInvoker.H>
#include <hwpf/fapi/fapiMvpdAccess.H>
#include <hwpf/hwpf_reasoncodes.H>
#include <slave_sbe.H>
#include <p8_build_pstate_datablock.H>
#include <proc_get_voltage.H>
#include <pstates.h>
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <vpd/mvpdenums.H>
#include <initserviceif.H>

extern trace_desc_t* g_fapiTd;

using namespace TARGETING;

namespace FREQVOLTSVC
{

    //**************************************************************************
    // FREQVOLTSVC::setSysFreq
    //**************************************************************************
    errlHndl_t setSysFreq()
    {
        errlHndl_t l_err = NULL;
        uint32_t l_sysHighestPowerSaveFreq = 0x0;
        TARGETING::ATTR_NOMINAL_FREQ_MHZ_type l_sysNomFreq = 0x0;
        TARGETING::ATTR_FREQ_CORE_MAX_type l_sysLowestTurboFreq = 0x0;

        // Get system frequency
        l_err = getSysFreq(l_sysHighestPowerSaveFreq,
                           l_sysNomFreq,
                           l_sysLowestTurboFreq);
        if (l_err != NULL)
        {
            TRACFCOMP( g_fapiTd,ERR_MRK"Error getting system frequency");
        }
        else
        {
            // Successfully got system frequency. Now update
            // system attributes.

            //Get the top level (system) target  handle
            TARGETING::Target* l_pTopLevel = NULL;
            (void)TARGETING::targetService().getTopLevelTarget(l_pTopLevel);

            // Assert on failure getting system target
            assert( l_pTopLevel != NULL );

            // Top level target successfully retrieved.
            // Set nominal frequency attribute
            (void)l_pTopLevel->setAttr
                           < TARGETING::ATTR_NOMINAL_FREQ_MHZ > (l_sysNomFreq);

            // Set max turbo frequency attribute
            (void)l_pTopLevel->setAttr
                       < TARGETING::ATTR_FREQ_CORE_MAX > (l_sysLowestTurboFreq);

            // Set min freq attribute based on power save
            (void)l_pTopLevel->setAttr<TARGETING::ATTR_MIN_FREQ_MHZ>
                                                    (l_sysHighestPowerSaveFreq);

            verifyBootFreq(l_pTopLevel);
        }

        return l_err;
    }

    //**************************************************************************
    // FREQVOLTSVC::verifyBootFreq
    //**************************************************************************
    void verifyBootFreq(TARGETING::Target* const i_pTarget)
    {
        TARGETING::ATTR_MIN_FREQ_MHZ_type l_sysMinFreq =
                   i_pTarget->getAttr<TARGETING::ATTR_MIN_FREQ_MHZ>();
        TARGETING::ATTR_BOOT_FREQ_MHZ_type l_boot_freq_mhz =
                   i_pTarget->getAttr<TARGETING::ATTR_BOOT_FREQ_MHZ>();

        l_boot_freq_mhz = (l_sysMinFreq > l_boot_freq_mhz) ? l_sysMinFreq:
                                                             l_boot_freq_mhz;

        i_pTarget->setAttr<TARGETING::ATTR_BOOT_FREQ_MHZ>(l_boot_freq_mhz);
    }

    //**************************************************************************
    // FREQVOLTSVC::getSysFreq
    //**************************************************************************
    errlHndl_t getSysFreq(
            uint32_t & o_sysVPDPowerSaveMinFreqMhz,
            TARGETING::ATTR_NOMINAL_FREQ_MHZ_type & o_sysNomFreqMhz,
            TARGETING::ATTR_FREQ_CORE_MAX_type & o_sysVPDTurboMaxFreqMhz)
    {
        uint32_t   l_minsysVPDTurboMaxFreqMhz = 0;
        uint32_t   l_maxsysVPDPowerSaveMinFreqMhz = 0;
        fapi::ReturnCode l_rc;
        errlHndl_t l_err = NULL;

        do
        {
            o_sysNomFreqMhz = 0;
            o_sysVPDTurboMaxFreqMhz = 0;
            o_sysVPDPowerSaveMinFreqMhz = 0;

            //Filter functional unit
            TARGETING::PredicateIsFunctional l_isFunctional;

            // Filter core unit
            TARGETING::PredicateCTM l_coreUnitFilter(TARGETING::CLASS_UNIT,
                                                     TARGETING::TYPE_CORE);

            //Filter functional cores
            TARGETING::PredicatePostfixExpr l_funcCoreUnitFilter;

            // core units AND functional
            l_funcCoreUnitFilter.push(&l_coreUnitFilter).push
                                                        (&l_isFunctional).And();

            // Loop through all the targets, looking for functional core units.
            TARGETING::TargetRangeFilter l_pFilter(
                                             TARGETING::targetService().begin(),
                                             TARGETING::targetService().end(),
                                             &l_funcCoreUnitFilter);
            // Assert if no functional cores are found
            assert(l_pFilter);

            bool l_copyOnce = true;

            // Loop through functional cores to get frequency
            for(; l_pFilter; ++l_pFilter )
            {
                TARGETING::Target * l_pTarget = *l_pFilter;

                fapi::voltageBucketData_t l_poundVdata = {0};

                // Get Parent Chip target
                const TARGETING::Target * l_pChipTarget =
                                                    getParentChip(l_pTarget);

                // Get core number for record number
                TARGETING::ATTR_CHIP_UNIT_type l_coreNum =
                        l_pTarget->getAttr<TARGETING::ATTR_CHIP_UNIT>();

                uint32_t l_record = (uint32_t) MVPD::LRP0 + l_coreNum;

                // Get #V bucket data
                l_rc = fapiGetPoundVBucketData(l_pChipTarget,
                                               l_record,
                                               l_poundVdata);
                if(l_rc)
                {
                    TRACFCOMP( g_fapiTd,ERR_MRK"Error getting #V data for HUID:"
                             "0x%08X",
                             l_pTarget->getAttr<TARGETING::ATTR_HUID>());

                    // Convert fapi returnCode to Error handle
                    l_err = fapiRcToErrl(l_rc);

                    break;
                }

                uint32_t l_sysVPDPowerSaveMinFreqMhz = l_poundVdata.PSFreq;
                TARGETING::ATTR_NOMINAL_FREQ_MHZ_type l_sysNomFreqMhz =
                                l_poundVdata.nomFreq;
                TARGETING::ATTR_FREQ_CORE_MAX_type l_sysVPDTurboMaxFreqMhz =
                                l_poundVdata.turboFreq;
                TRACFCOMP(g_fapiTd,INFO_MRK"Nominal freq is: [0x%08X]. Turbo "
                          "freq is: [0x%08x]. PowerSave freq is: [0x%08X]",
                          l_sysNomFreqMhz, l_sysVPDTurboMaxFreqMhz,
                          l_sysVPDPowerSaveMinFreqMhz );

                if( true == l_copyOnce)
                {
                    o_sysNomFreqMhz = l_sysNomFreqMhz;
                    l_minsysVPDTurboMaxFreqMhz = l_sysVPDTurboMaxFreqMhz;
                    l_maxsysVPDPowerSaveMinFreqMhz =
                                             l_sysVPDPowerSaveMinFreqMhz;
                    l_copyOnce = false;
                }

                // frequency is never zero so create error if it is zero.
                if( (l_sysNomFreqMhz == 0)         ||
                    (l_sysVPDTurboMaxFreqMhz == 0) ||
                    (l_sysVPDPowerSaveMinFreqMhz == 0) )
                {
                    TRACFCOMP(g_fapiTd,ERR_MRK"Frequency is zero, "
                             "nominal freq: 0x%04X,turbo freq: 0x%08X",
                             "PowerSave freq is: [0x%08X]",
                             l_sysNomFreqMhz,
                             l_sysVPDTurboMaxFreqMhz,
                             l_sysVPDPowerSaveMinFreqMhz);

                    /*@
                     * @errortype
                     * @moduleid         fapi::MOD_GET_SYS_FREQ
                     * @reasoncode       fapi::RC_INVALID_DATA
                     * @userdata1[0:31]  Proc HUID
                     * @userdata1[32:63] Nominal frequency
                     * @userdata2[0:31]  Max Turbo frequency from VPD
                     * @userdata2[32:63] Min Power Save frequency from VPD
                     * @devdesc          Either nominal, max turbo or min power
                     *                   save frequency for the processor HUID
                     *                   (userdata1) is zero
                     */
                    l_err =
                        new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         fapi::MOD_GET_SYS_FREQ,
                                         fapi::RC_INVALID_DATA,
                    TWO_UINT32_TO_UINT64(
                                     l_pTarget->getAttr<TARGETING::ATTR_HUID>(),
                                     l_sysNomFreqMhz),
                    TWO_UINT32_TO_UINT64(l_sysVPDTurboMaxFreqMhz,
                                         l_sysVPDPowerSaveMinFreqMhz));

                    // Callout HW as VPD data is incorrect
                    l_err->addHwCallout(l_pTarget, HWAS::SRCI_PRIORITY_HIGH,
                                         HWAS::DECONFIG, HWAS::GARD_NULL);

                    break;
                }

                // Validate nominal frequency. If differs,
                // create error and stop processing further.
                if( o_sysNomFreqMhz != l_sysNomFreqMhz )
                {
                    TRACFCOMP(g_fapiTd,ERR_MRK
                             "Nominal Frequency:[0x%04X] does not "
                             "match with other core nominal frequency:[0x%04X]",
                             l_sysNomFreqMhz, o_sysNomFreqMhz);

                    /*@
                     * @errortype
                     * @moduleid    fapi::MOD_GET_SYS_FREQ
                     * @reasoncode  fapi::RC_INVALID_FREQ
                     * @userdata1   Invalid frequency
                     * @userdata2   Expected frequency
                     * @devdesc     Nominal frequency(userdata1) does not match
                     *              nominal frequency(userdata2) on other cores.
                     *              Should be the same for all chips.
                     */
                    l_err =
                        new ERRORLOG::ErrlEntry(
                                         ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                         fapi::MOD_GET_SYS_FREQ,
                                         fapi::RC_INVALID_FREQ,
                                         l_sysNomFreqMhz,
                                         o_sysNomFreqMhz);

                    // Callout HW as VPD data is incorrect
                    l_err->addHwCallout(l_pTarget, HWAS::SRCI_PRIORITY_HIGH,
                                         HWAS::DECONFIG, HWAS::GARD_NULL);

                    break;
                }

                // Save the min turbo freq
                if (l_sysVPDTurboMaxFreqMhz < l_minsysVPDTurboMaxFreqMhz)
                {
                    l_minsysVPDTurboMaxFreqMhz = l_sysVPDTurboMaxFreqMhz;
                }
                // Save the max powersave freq
                if (l_sysVPDPowerSaveMinFreqMhz >
                                    l_maxsysVPDPowerSaveMinFreqMhz)
                {
                    l_maxsysVPDPowerSaveMinFreqMhz =
                                    l_sysVPDPowerSaveMinFreqMhz;
                }

            } // end for loop
            if (l_err != NULL)
            {
                break;
            }

            // Get min turbo freq
            o_sysVPDTurboMaxFreqMhz = l_minsysVPDTurboMaxFreqMhz;

            // Get max powersave freq
            o_sysVPDPowerSaveMinFreqMhz = l_maxsysVPDPowerSaveMinFreqMhz;

        } while (0);

        TRACFCOMP(g_fapiTd,EXIT_MRK"o_sysNomFreqMhz: 0x%08X, "
                  "o_sysVPDTurboMaxFreqMhz: 0x%08X, "
                  "o_sysVPDPowerSaveMinFreqMhz: 0x%08X",
                   o_sysNomFreqMhz, o_sysVPDTurboMaxFreqMhz,
                   o_sysVPDPowerSaveMinFreqMhz );

        return l_err;
    }

    //**************************************************************************
    // FREQVOLTSVC::runP8BuildPstateDataBlock
    //**************************************************************************
    errlHndl_t runP8BuildPstateDataBlock(
                                           const TARGETING::Target * i_procChip,
                                           PstateSuperStructure * o_data)
    {
        errlHndl_t l_err = NULL;

        // Assert on NULL input target
        assert(i_procChip != NULL);

        // convert to fapi target
        fapi::Target l_fapiProcChip(fapi::TARGET_TYPE_PROC_CHIP,
                              reinterpret_cast<void *>
                              (const_cast<TARGETING::Target*>(i_procChip)) );

        FAPI_INVOKE_HWP(l_err, p8_build_pstate_datablock,l_fapiProcChip,o_data);

        if( l_err != NULL)
        {
            TRACFCOMP( g_fapiTd,ERR_MRK"Error from HWP: "
                     "p8_build_pstate_datablock for target HUID: 0x%08X",
                     i_procChip->getAttr<TARGETING::ATTR_HUID>());
        }

        return l_err;
    }

    //**************************************************************************
    // FREQVOLTSVC::runProcGetVoltage
    //**************************************************************************
    errlHndl_t runProcGetVoltage(
                    TARGETING::Target * io_procChip,
                    const uint32_t i_bootFreqMhz)
    {
        TRACDCOMP(g_fapiTd,INFO_MRK"Enter runProcGetVoltage");

        uint8_t l_vdd_vid = 0;
        uint8_t l_vcs_vid = 0;

        errlHndl_t l_err = NULL;
        TARGETING::ATTR_BOOT_VOLTAGE_type l_boot_voltage_info =
                                    PROC_BOOT_VOLT_PORT0_ENABLE;

        TRACDCOMP(g_fapiTd,INFO_MRK"i_bootFreqMhz: 0x%08X",i_bootFreqMhz);

        // Assert on NULL input target
        // If the target is NULL, we have NO functional PROCS.
        // Terminate IPL
        assert(io_procChip != NULL);

        // convert to fapi target
        fapi::Target l_fapiProcChip(fapi::TARGET_TYPE_PROC_CHIP,
                                  reinterpret_cast<void *>
                                 (const_cast<TARGETING::Target*>(io_procChip)));

        // Invoke HW procedure
        FAPI_INVOKE_HWP(l_err, proc_get_voltage,l_fapiProcChip,i_bootFreqMhz,
                        l_vdd_vid,l_vcs_vid);

        if( l_err != NULL)
        {
            TRACFCOMP( g_fapiTd,ERR_MRK"Error from HWP: proc_get_voltage: "
                     "i_bootFreq: 0x%08X, "
                     "HUID: 0x%08X", i_bootFreqMhz,
                     io_procChip->getAttr<TARGETING::ATTR_HUID>());
        }

        TRACDCOMP("Vdd: 0x%02x, vcs: 0x%02x", l_vdd_vid, l_vcs_vid);

        // create boot voltage value
        l_boot_voltage_info |= ( ( static_cast<uint32_t>(l_vdd_vid) <<
                  PROC_BOOT_VOLT_VDD_SHIFT) & ( PROC_BOOT_VOLT_VDD_MASK ) );
        l_boot_voltage_info |= ( ( static_cast<uint32_t>(l_vcs_vid) <<
                  PROC_BOOT_VOLT_VCS_SHIFT) & ( PROC_BOOT_VOLT_VDD_MASK ) );

        // set ATTR_PROC_BOOT_VOLTAGE_VID
        io_procChip->setAttr<
             TARGETING::ATTR_PROC_BOOT_VOLTAGE_VID>( l_boot_voltage_info );


        return l_err;
    }

} // end namespace FREQVOLTSVC

