/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_slave_sbe_config.C $         */
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
#include <hwas/common/hwas.H>
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
    TARGETING::ATTR_MASTER_MBOX_SCRATCH_type l_scratchRegs;
    assert(l_sys->tryGetAttr
             <TARGETING::ATTR_MASTER_MBOX_SCRATCH>(l_scratchRegs),
           "call_host_slave_sbe_config() failed to get MASTER_MBOX_SCRATCH");
    l_scratch3.data32 = l_scratchRegs[INITSERVICE::SPLESS::SCRATCH_3];

    // turn off the istep bit
    l_scratch3.istepMode = 0;

    // write the attribute
    l_sys->setAttr<ATTR_BOOT_FLAGS>(l_scratch3.data32);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "ATTR_BOOT_FLAGS=%.8X", l_scratch3.data32 );
    if(l_scratch3.overrideSecurity)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
            "WARNING: Requesting security disable on non-master processors.");
    }
    if(l_scratch3.allowAttrOverrides)
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, INFO_MRK
            "WARNING: Requesting allowing Attribute Overrides on "
            "non-master processors even if secure mode.");
    }

    // grab the boot flags from the master proc
    INITSERVICE::SPLESS::MboxScratch5_t l_scratch5;
    l_scratch5.data32 = l_scratchRegs[INITSERVICE::SPLESS::SCRATCH_5];
    

    // execute p9_setup_sbe_config.C for non-primary processor targets
    TARGETING::TargetHandleList l_cpuTargetList;
    getAllChips(l_cpuTargetList, TYPE_PROC);

    for (const auto & l_cpu_target: l_cpuTargetList)
    {
        //Setup EC_GARD and EQ_GARD attrs on the proc before setting up sbe_config
        HWAS::setChipletGardsOnProc(l_cpu_target);

        // do not call HWP on master processor
        if (l_cpu_target != l_pMasterProcTarget)
        {
            const fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP>
                l_fapi2_proc_target (l_cpu_target);

            l_cpu_target->setAttr<ATTR_MC_SYNC_MODE>(l_scratch5.mcSyncMode);

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

            l_errl = SBE::updateSbeBootSeeprom(l_cpu_target);

            if( l_errl )
            {
                ErrlUserDetailsTarget(l_cpu_target).addToLog( l_errl );

                // Create IStep error log and cross ref error that occurred
                l_stepError.addErrorDetails( l_errl );

                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "ERROR : updateSbeBootSeeprom target %.8X, "
                           "PLID=0x%x",
                           TARGETING::get_huid(l_cpu_target),
                           l_errl->plid() );

                // Commit Error
                errlCommit( l_errl, ISTEP_COMP_ID );
            }
        }
    } // end of cycling through all processor chips

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
             "call_host_slave_sbe_config exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();

}

};
