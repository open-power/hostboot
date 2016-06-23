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
#include <initservice/mboxRegs.H>

using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_08
{
//******************************************************************************
// call_host_slave_sbe function
//******************************************************************************
void* call_host_slave_sbe_config(void *io_pArgs)
{
    errlHndl_t l_errl = NULL;
    IStepError  l_stepError;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_host_slave_sbe_config entry" );

    TARGETING::Target* l_pMasterProcTarget = NULL;
    TARGETING::targetService().masterProcChipTargetHandle(l_pMasterProcTarget);

    TARGETING::Target* l_sys = NULL;
    targetService().getTopLevelTarget(l_sys);
    assert( l_sys != NULL );

    // Setup the boot flags attribute for the slaves based on the data
    //  from the master proc
    INITSERVICE::SPLESS::MboxScratch3_t l_scratch3;
    uint64_t l_scratch3scom = 0;
    size_t scomsize = sizeof(l_scratch3scom);
    l_errl = deviceRead( l_pMasterProcTarget,
                         &l_scratch3scom,
                         scomsize,
                         DEVICE_SCOM_ADDRESS(
                           INITSERVICE::SPLESS::MBOX_SCRATCH_REG3 ) );
    if( l_errl )
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, ISTEP_COMP_ID );

        // Just make some reasonable guesses...
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Failed to read MBOX Scratch3" );

        l_scratch3.data32 = 0;
        l_scratch3.fspAttached = INITSERVICE::spBaseServicesEnabled();
        l_scratch3.sbeFFDC = 0;
        l_scratch3.sbeInternalFFDC = 1;
    }
    else
    {
        // data is in bits 0:31
        l_scratch3.data32 = static_cast<uint32_t>(l_scratch3scom >> 32);

        // turn off the istep bit
        l_scratch3.istepMode = 0;
    }
    // write the attribute
    l_sys->setAttr<ATTR_BOOT_FLAGS>(l_scratch3.data32);


    // execute p9_setup_sbe_config.C for non-primary processor targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

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
                errlCommit( l_errl, ISTEP_COMP_ID );
            }
        }
    } // end of cycling through all processor chips

    // Resolve the side characteristics of the Processor SBE Seeproms
    errlHndl_t err = SBE::resolveProcessorSbeSeeproms();
    if ( err )
    {
        // Create IStep error log and cross reference error that occurred
        l_stepError.addErrorDetails( err );

        // Commit Error
        errlCommit( err, ISTEP_COMP_ID );
    }

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_host_slave_sbe_config exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}

};
