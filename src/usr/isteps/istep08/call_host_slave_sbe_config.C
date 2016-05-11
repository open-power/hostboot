/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_slave_sbe_config.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
 *  @file call_host_slave_sbe_config.C
 *
 *  Support file for IStep: slave_sbe
 *   Slave SBE
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <i2c/i2cif.H>
#include <sbe/sbeif.H>
//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

#include <fapi2/target.H>
#include <fapi2/plat_hwp_invoker.H>

#include <errl/errlmanager.H>

#include <isteps/hwpisteperror.H>

#include <errl/errludtarget.H>

#include <p9_setup_sbe_config.H>

using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_08
{
//******************************************************************************
// set_proc_boot_voltage_vid
//******************************************************************************
errlHndl_t set_proc_boot_voltage_vid()
{
    errlHndl_t l_errl = NULL;
    IStepError l_stepError;
    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
             "ENTER set_proc_boot_voltage_vid()");
    do
    {
        // Get the top level target/system target
        Target* l_pTopLevelTarget = NULL;
        targetService().getTopLevelTarget(l_pTopLevelTarget);

        // If there is no top level target, terminate
        assert(l_pTopLevelTarget, "ERROR: Top level "
              "target not found - slave_sbe.C::set_proc_boot_voltage_vid");

        // Get all Procs
        PredicateCTM l_proc(CLASS_CHIP, TYPE_PROC);
        PredicateIsFunctional l_functional;
        PredicatePostfixExpr l_procs;

        l_procs.push(&l_proc).push(&l_functional).And();

        TargetRangeFilter l_filter( targetService().begin(),
                                    targetService().end(),
                                    &l_procs );

        //@TODO: RTC:153745 add this get ATTR
        /*
        ATTR_BOOT_FREQ_MHZ_type l_boot_freq_mhz =
                   l_pTopLevelTarget->getAttr<ATTR_BOOT_FREQ_MHZ>();
        for(; l_filter; ++l_filter)
        {

            l_errl = FREQVOLTSVC::runProcGetVoltage(*l_filter,
                                                    l_boot_freq_mhz);
            if( l_errl )
            {
                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                            "ERROR: calling runProcGetVoltage for Proc "
                            "Target HUID[0x%08X]",
                            l_filter->getAttr<ATTR_HUID>());


                // Deconfig the processor
                l_errl->addHwCallout(*l_filter,
                        HWAS::SRCI_PRIORITY_LOW,
                        HWAS::DECONFIG,
                        HWAS::GARD_NULL);


                // Commit error log
                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }
*/

    } while( 0 );

    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
             "EXIT set_proc_boot_voltage_vid()");
    return l_errl;
}

//******************************************************************************
// call_host_slave_sbe function
//******************************************************************************
void* call_host_slave_sbe_config(void *io_pArgs)
{
    errlHndl_t l_errl = NULL;
    IStepError  l_stepError;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_host_slave_sbe_config entry" );

    // execute p9_setup_sbe_config.C for non-primary processor targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    TARGETING::Target* l_pMasterProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        // do not call HWP on master processor
        if (l_cpu_target != l_pMasterProcTarget)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (l_cpu_target);

            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Running p9_setup_sbe_config HWP on processor target %.8X",
                     TARGETING::get_huid(l_cpu_target) );

            FAPI_INVOKE_HWP(l_errl, p9_setup_sbe_config, l_fapi2_proc_target);

            if( l_errl )
            {
                ErrlUserDetailsTarget(l_cpu_target).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_errl );

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                         "ERROR : call p9_setup_sbe_config, "
                         "PLID=0x%x", l_errl->plid() );

                // Commit Error
                errlCommit( l_errl, HWPF_COMP_ID );
            }
        }
    } // end of cycling through all processor chips

#ifdef CONFIG_HTMGT
    // Set system frequency attributes
    l_errl = FREQVOLTSVC::setSysFreq();
    if (l_errl )
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }
#endif // CONFIG_HTMGT

    // If there is no FSP, set ATTR_PROC_BOOT_VOLTAGE_VID
    if (!INITSERVICE::spBaseServicesEnabled())
    {
        l_errl = set_proc_boot_voltage_vid();
        if( l_errl )
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                     "Error setting PROC_BOOT_VOLTAGE_VID: "
                     "slave_sbe.C::call_host_slave_sbe_config()" );
            // Create IStep error log
            l_stepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
        }

        // Enable SBE interrupt for OP systems
        TARGETING::Target* l_sys = NULL;
        targetService().getTopLevelTarget(l_sys);
        assert( l_sys != NULL );

        //@TODO: RTC:153745 Add this set ATTR call
        //TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "Enabling SBE interrupt for OP systems");
        //l_sys->setAttr<ATTR_FORCE_SKIP_SBE_MASTER_INTR_SERVICE>(0);
    }

    // Resolve the side characteristics of the Processor SBE Seeproms
#if 0
    //@TODO-RTC:138226
    errlHndl_t err = SBE::resolveProcessorSbeSeeproms();
    if ( err )
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( err );

        // Commit Error
        errlCommit( err, HWPF_COMP_ID );
    }
#endif
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_host_slave_sbe_config exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}

};
