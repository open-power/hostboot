/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/call_host_voltage_config.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <fapi2.H>
#include <fapi2/plat_hwp_invoker.H>

//Targeting
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

#include    <p9_pm_get_poundv_bucket.H>
#include    <p9_setup_evid.H>

//SBE
#include    <sbe/sbeif.H>

using namespace TARGETING;


namespace ISTEP_06
{

void* call_host_voltage_config( void *io_pArgs )
{
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_voltage_config entry" );

    ISTEP_ERROR::IStepError l_stepError;

    errlHndl_t l_err = nullptr;
    Target * l_sys = nullptr;
    TargetHandleList l_procList;
    TargetHandleList l_eqList;
    fapi2::voltageBucketData_t l_voltageData;
    fapi2::ReturnCode l_rc;

    uint32_t l_nominalFreq = 0;     //ATTR_NOMINAL_FREQ_MHZ
    uint32_t l_floorFreq = 0;       //ATTR_FREQ_FLOOR_MHZ
    uint32_t l_ceilingFreq = 0;     //ATTR_FREQ_CORE_CEILING_MHZ
    uint32_t l_ultraTurboFreq = 0;  //ATTR_ULTRA_TURBO_FREQ_MHZ
    uint32_t l_turboFreq = 0;       //ATTR_FREQ_CORE_MAX
    uint32_t l_vddBootVoltage = 0;  //ATTR_VDD_BOOT_VOLTAGE
    uint32_t l_vdnBootVoltage = 0;  //ATTR_VDN_BOOT_VOLTAGE
    uint32_t l_vcsBootVoltage = 0;  //ATTR_VCS_BOOT_VOLTAGE
    uint32_t l_nestFreq = 0;        //ATTR_FREQ_PB_MHZ

    bool l_firstPass = true;

    PredicateCTM l_eqFilter(CLASS_UNIT, TYPE_EQ);
    PredicateHwas l_predPres;
    l_predPres.present(true);
    PredicatePostfixExpr l_presentEqs;
    l_presentEqs.push(&l_eqFilter).push(&l_predPres).And();


    do
    {
        // Get the system target
        targetService().getTopLevelTarget(l_sys);

        // Set the Nest frequency to whatever we boot with
        l_err = SBE::getBootNestFreq( l_nestFreq );

        if( l_err )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "call_host_voltage_config.C::"
                    "Failed getting the boot nest frequency from the SBE");
            break;
        }

        l_sys->setAttr<TARGETING::ATTR_FREQ_PB_MHZ>( l_nestFreq );

        // Get the child proc chips
        getChildAffinityTargets( l_procList,
                                 l_sys,
                                 CLASS_CHIP,
                                 TYPE_PROC );

        // for each proc target
        for( const auto & l_proc : l_procList )
        {
            // get the child EQ targets
            targetService().getAssociated(
                    l_eqList,
                    l_proc,
                    TargetService::CHILD_BY_AFFINITY,
                    TargetService::ALL,
                    &l_presentEqs );


            if( l_eqList.empty() )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "No children of proc 0x%x found to have type EQ",
                        get_huid(l_proc));



                /*@
                 * @errortype
                 * @moduleid    ISTEP::MOD_VOLTAGE_CONFIG
                 * @reasoncode  ISTEP::RC_NO_PRESENT_EQS
                 * @userdata1   Parent PROC huid
                 * @devdesc     No present EQs found on processor
                 * @custdesc    A problem occurred during the IPL of the system.
                 */
                l_err = new ERRORLOG::ErrlEntry
                        (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                         ISTEP::MOD_VOLTAGE_CONFIG,
                         ISTEP::RC_NO_PRESENT_EQS,
                         get_huid(l_proc),
                         0,
                         true /*HB SW error*/ );
                break;
            }
            //  for each child EQ target
            for( const auto & l_eq : l_eqList )
            {
                // cast to fapi2 target
                fapi2::Target<fapi2::TARGET_TYPE_EQ> l_fapiEq( l_eq );

                // get the #V data for this EQ
                FAPI_INVOKE_HWP( l_err,
                                 p9_pm_get_poundv_bucket,
                                 l_fapiEq,
                                 l_voltageData);

                if( l_err )
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                            "Error in call_host_voltage_config::p9_pm_get_poundv_bucket");

                    // Create IStep error log and cross reference occurred error
                    l_stepError.addErrorDetails( l_err );

                    // Commit Error
                    errlCommit( l_err, ISTEP_COMP_ID );

                    continue;
                }

                // Save the voltage data for future comparison
                if( l_firstPass )
                {
                    l_nominalFreq = l_voltageData.nomFreq;
                    l_floorFreq = l_voltageData.PSFreq;
                    l_ceilingFreq = l_voltageData.turboFreq;
                    l_ultraTurboFreq = l_voltageData.uTurboFreq;
                    l_turboFreq = l_voltageData.turboFreq;
                    l_vddBootVoltage = l_voltageData.VddPSVltg;
                    l_vdnBootVoltage = l_voltageData.VddPSVltg;
                    l_vcsBootVoltage = l_voltageData.VcsPSVltg;
                    l_firstPass = false;
                }
                else
                {
                    // save it to variable and compare agains other nomFreq
                    // All of the buckets should report the same Nominal frequency
                    if( l_nominalFreq != l_voltageData.nomFreq )
                    {
                        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                                "NOMINAL FREQ MISMATCH! expected: %d actual: %d",
                                l_nominalFreq, l_voltageData.nomFreq );

                        l_err = new ERRORLOG::ErrlEntry
                            (ERRORLOG::ERRL_SEV_CRITICAL_SYS_TERM,
                             ISTEP::MOD_VOLTAGE_CONFIG,
                             ISTEP::RC_NOMINAL_FREQ_MISMATCH,
                             l_nominalFreq,
                             l_voltageData.nomFreq,
                             false );

                        l_err->addHwCallout(l_proc,
                                            HWAS::SRCI_PRIORITY_HIGH,
                                            HWAS::DECONFIG,
                                            HWAS::GARD_NULL );

                        // Create IStep error log and cross reference occurred error
                        l_stepError.addErrorDetails( l_err );

                        // Commit Error
                        errlCommit( l_err, ISTEP_COMP_ID );

                        continue;
                    }

                    // Floor frequency is the maximum of the Power Save Freqs
                    l_floorFreq =
                    (l_voltageData.PSFreq > l_floorFreq) ? l_voltageData.PSFreq : l_floorFreq;

                    // Ceiling frequency is the minimum of the Turbo Freqs
                    l_ceilingFreq = (l_voltageData.turboFreq < l_ceilingFreq) ?
                     l_voltageData.turboFreq : l_ceilingFreq;

                    // Ultra Turbo frequency is the minimum of the Ultra Turbo Freqs
                    l_ultraTurboFreq = (l_voltageData.uTurboFreq < l_ultraTurboFreq) ?
                     l_voltageData.uTurboFreq : l_ultraTurboFreq;

                    // Turbo frequency is the minimum of the Turbo Freqs
                    l_turboFreq = l_ceilingFreq;
                }

            } // EQ for-loop


            // set the approprate attributes on the processor
            l_proc->setAttr<ATTR_VDD_BOOT_VOLTAGE>( l_vddBootVoltage );

            l_proc->setAttr<ATTR_VDN_BOOT_VOLTAGE>( l_vdnBootVoltage );

            l_proc->setAttr<ATTR_VCS_BOOT_VOLTAGE>( l_vcsBootVoltage );

            TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Setting VDD/VDN/VCS boot voltage for proc huid = 0x%x"
                    " VDD = %d, VDN = %d, VCS = %d",
                    get_huid(l_proc),
                    l_vddBootVoltage,
                    l_vdnBootVoltage,
                    l_vcsBootVoltage );


            // call p9_setup_evid for each processor
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>l_fapiProc(l_proc);
            FAPI_INVOKE_HWP(l_err, p9_setup_evid, l_fapiProc, COMPUTE_VOLTAGE_SETTINGS);

            if( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "Error in call_host_voltage_config::p9_setup_evid");

                // Create IStep error log and cross reference occurred error
                l_stepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );
                continue;
            }

        } // PROC for-loop

        // If we hit an error from p9_setup_evid, quit
        if( l_err )
        {
            break;
        }

        // set the frequency system targets
        l_sys->setAttr<ATTR_NOMINAL_FREQ_MHZ>( l_nominalFreq );

        l_sys->setAttr<ATTR_MIN_FREQ_MHZ>( l_floorFreq );

        l_sys->setAttr<ATTR_FREQ_CORE_CEILING_MHZ>( l_ceilingFreq );

        l_sys->setAttr<ATTR_FREQ_CORE_MAX>( l_turboFreq );

        l_sys->setAttr<ATTR_ULTRA_TURBO_FREQ_MHZ>(l_ultraTurboFreq);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "Setting System Frequency Attributes: "
                "Nominal = %d, Floor = %d, Ceiling = %d, "
                "Turbo = %d, UltraTurbo = %d",
                l_nominalFreq, l_floorFreq, l_ceilingFreq,
                l_turboFreq, l_ultraTurboFreq );

    } while( 0 );

    if( l_err )
    {
        // Create IStep error log and cross reference occurred error
        l_stepError.addErrorDetails( l_err );

        // Commit Error
        errlCommit( l_err, ISTEP_COMP_ID );

    }
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_voltage_config exit" );

    return l_stepError.getErrorHandle();
}

};
