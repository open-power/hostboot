/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_host_sbe_update.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020,2022                        */
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
#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
#include    <isteps/hwpisteperror.H>
#include    <istepHelperFuncs.H>
#include    <isteps/istep_reasoncodes.H>
#include    <initservice/isteps_trace.H>
#include    <initservice/istepdispatcherif.H>
#include    <initservice/initserviceif.H>
#include    <pldm/requests/pldm_pdr_requests.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/target.H>

#include    <sbe/sbeif.H>
#include    <pnor/pnorif.H>
#include    <i2c/i2cif.H>
#include    <console/consoleif.H>
#include    <config.h>
#include    <sys/time.h>
#include    <hwas/common/hwasCommon.H>

// fapi2 HWP invoker
#include    <fapi2/plat_hwp_invoker.H>

#include    <fapi2.H>
#include    <p10_sbe_lpc_init.H>

// PRDF
#include    <diag/prdf/prdfMain.H>

// Easy macro replace for unit testing
//#define TRACUCOMP(args...)  TRACFCOMP(args)
#define TRACUCOMP(args...)

using   namespace   ISTEP_ERROR;
using   namespace   ISTEP;
using   namespace   TARGETING;
using   namespace   ERRORLOG;

namespace ISTEP_10
{

void* call_host_sbe_update (void *io_pArgs)
{
    errlHndl_t  l_errl  =   NULL;
    IStepError l_StepError;
    bool l_testAltMaster = true;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_sbe_update entry" );

    // This step uses significant memory resources. PRD, if it has been
    // initialized, will also use significant memory resources. To ensure this
    // step has enough resources to complete in a timely fashion, we will
    // uninitialize PRD to free up the needed resources.
    PRDF::uninitialize();

    do
    {

        // Slave processors should now use Host I2C Access Method
        I2C::i2cSetAccessMode( I2C::I2C_SET_ACCESS_MODE_PROC_HOST );

        // Call to check state of Processor SBE SEEPROMs and
        // make any necessary updates
        l_errl = SBE::updateProcessorSbeSeeproms(
            SBE::KEY_TRANSITION_PERM::ALLOW_KEY_TRANSITION);

        if (l_errl)
        {
            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl);
            // Commit error
            errlCommit( l_errl, HWPF_COMP_ID );
            break;
        }

        // Run LPC Init on Alt Master Procs
        // Get list of all processors
        TARGETING::TargetHandleList l_procList;
        TARGETING::getAllChips(l_procList,
                               TARGETING::TYPE_PROC,
                               true); // true: return functional targets

        // Loop through all processors
        for (const auto & l_procTarg : l_procList)
        {
            // Check if processor is MASTER_CANDIDATE
            TARGETING::ATTR_PROC_MASTER_TYPE_type type_enum =
                       l_procTarg->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();

            if ( type_enum == TARGETING::PROC_MASTER_TYPE_MASTER_CANDIDATE )
            {
                // Initialize the LPC Bus by calling the p10_sbe_lpc_init hwp
                fapi2::Target <fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_target (l_procTarg);
                FAPI_INVOKE_HWP(l_errl, p10_sbe_lpc_init_any, l_fapi_target, true);

                if (l_errl)
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                               ERR_MRK"PNOR::validateAltMaster> p10_sbe_lpc_init target 0x%.8X"
                               TRACE_ERR_FMT,
                               get_huid(l_procTarg),
                               TRACE_ERR_ARGS(l_errl));

                    // capture the target data in the elog
                    ErrlUserDetailsTarget(l_procTarg).addToLog(l_errl);
                    //Remove any processor deconfigure/gard information, we
                    // only need the deconfig/gard actions for the PNOR Part
                    // and do not want to deconfigure the entire proc because
                    // of a PNOR part problem
                    l_errl->setGardType(l_procTarg,HWAS::GARD_NULL);
                    l_errl->setDeconfigState(l_procTarg,HWAS::NO_DECONFIG);
                    // Commit error
                    errlCommit( l_errl, HWPF_COMP_ID );
                    l_testAltMaster = false;
                }
                else
                {
                    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "SUCCESS running p10_sbe_lpc_init HWP on "
                           "target HUID %.8X", TARGETING::get_huid(l_procTarg));
                }
            }
        }

        // Call to Validate any Alternative Master's connection to PNOR
        // Any error returned should not fail istep
        if (l_testAltMaster == true)
        {
            l_errl = PNOR::validateAltMaster();
            if (l_errl)
            {
                for (const auto & l_procTarg : l_procList)
                {
                    // Check if processor is MASTER_CANDIDATE
                    TARGETING::ATTR_PROC_MASTER_TYPE_type type_enum =
                      l_procTarg->getAttr<TARGETING::ATTR_PROC_MASTER_TYPE>();

                    if ( type_enum == TARGETING::PROC_MASTER_TYPE_MASTER_CANDIDATE )
                    {
                        //Remove any processor deconfigure/gard information, we
                        // only need the deconfig/gard actions for the PNOR Part
                        // and do not want to deconfigure the entire proc because
                        // of a PNOR part problem
                        l_errl->setGardType(l_procTarg,HWAS::GARD_NULL);
                        l_errl->setDeconfigState(l_procTarg,HWAS::NO_DECONFIG);
                    }
                }
                // Commit error
                errlCommit( l_errl, HWPF_COMP_ID );
            }

#ifdef CONFIG_SUPPORT_EEPROM_CACHING
            else // Only do the copy if the basic access worked
            {
                // We need to keep the alt-pnor's version of the EECACHE in sync with
                //  the active copy to handle a future failover.
                l_errl = PNOR::copyPnorPartitionToAlt(PNOR::EECACHE);
                if (l_errl)
                {
                    TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"call_host_sbe_update PROBLEM syncing EECACHE to altpnor");
                    // we don't want to deconfigure any processors since we can recover
                    l_errl->removeGardAndDeconfigure();
                    // commit the log but do not kill the IPL (do not use captureError)
                    l_errl->setSev(ERRORLOG::ERRL_SEV_PREDICTIVE);
                    errlCommit( l_errl, ISTEP_COMP_ID );
                }
            }
#endif
        }

        // Set SEEPROM_VERSIONS_MATCH attributes for each processor
        // this will be used later on by the sbe_retry code to determine
        // if it is safe to switch seeprom sides during recovery attempts
        l_errl = SBE::querySbeSeepromVersions();
        if(l_errl)
        {
            l_StepError.addErrorDetails(l_errl);
            errlCommit( l_errl, HWPF_COMP_ID);
        }

   } while (0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_sbe_update exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();

}

};
