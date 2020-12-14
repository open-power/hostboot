/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_host_omi_init.C $                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2021                        */
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
 * @file    call_host_omi_init.C
 *
 *  Contains the HWP wrapper for Istep 12.11
 *      exp_omi_init
 *      p10_omi_init
 *      p10_disable_ocmb_i2c
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <istepHelperFuncs.H>          // captureError

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>

//HWP
#include    <exp_omi_init.H>
#include    <p10_omi_init.H>
#include    <p10_disable_ocmb_i2c.H>

// Explorer error logs
#include    <expscom/expscom_errlog.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{
void enableInbandScomsOCMB( TargetHandleList i_ocmbTargetList );

void* call_host_omi_init (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = nullptr;
    TRACFCOMP( g_trac_isteps_trace, "call_host_omi_init entry" );
    TargetHandleList l_ocmbTargetList;
    bool encounteredHwpError = false;
    do
    {
        // 12.11.a exp_omi_init.C
        //        - Initialize config space on the Explorers
        getAllChips(l_ocmbTargetList, TYPE_OCMB_CHIP);
        TRACFCOMP(g_trac_isteps_trace,
            "call_host_omi_init: %d ocmb chips found",
            l_ocmbTargetList.size());

        for (const auto & l_ocmb_target : l_ocmbTargetList)
        {
            TRACFCOMP( g_trac_isteps_trace,
                "exp_omi_init HWP target HUID 0x%.8x",
                get_huid(l_ocmb_target) );

            //  call the HWP with each target
            fapi2::Target<fapi2::TARGET_TYPE_OCMB_CHIP> l_fapi_ocmb_target
                    (l_ocmb_target);

            FAPI_INVOKE_HWP(l_err, exp_omi_init , l_fapi_ocmb_target);

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP(g_trac_isteps_trace,
                    "ERROR : call exp_omi_init HWP(): failed on target 0x%08X. "
                    TRACE_ERR_FMT,
                    get_huid(l_ocmb_target),
                    TRACE_ERR_ARGS(l_err));

                // Capture error
                captureErrorOcmbUpdateCheck(l_err, l_StepError, HWPF_COMP_ID, l_ocmb_target);
                encounteredHwpError = true;
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "SUCCESS : exp_omi_init HWP on target HUID 0x%.8x",
                    get_huid(l_ocmb_target) );
            }
        } // ocmb loop

        // Do not continue if an error was encountered
        if(encounteredHwpError)
        {
            TRACFCOMP( g_trac_isteps_trace,
                INFO_MRK "call_host_omi_init exited early because exp_omi_init "
                "had failures" );
            break;
        }

        // 12.11.b p10_omi_init.C
        //        - Finalize the OMI
        TargetHandleList l_mccTargetList;
        getAllChiplets(l_mccTargetList, TYPE_MCC);
        TRACFCOMP(g_trac_isteps_trace,
            "call_host_omi_init: %d MCCs found",
            l_mccTargetList.size());

        for (const auto & l_mcc_target : l_mccTargetList)
        {
            TRACFCOMP( g_trac_isteps_trace,
                "p10_omi_init HWP target HUID 0x%.8x",
                get_huid(l_mcc_target) );

            //  call the HWP with each target
            fapi2::Target<fapi2::TARGET_TYPE_MCC> l_fapi_mcc_target
                    (l_mcc_target);

            FAPI_INVOKE_HWP(l_err, p10_omi_init, l_fapi_mcc_target);

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP(g_trac_isteps_trace,
                    "ERROR : call p10_omi_init HWP(): failed on target 0x%08X. "
                    TRACE_ERR_FMT,
                    get_huid(l_mcc_target),
                    TRACE_ERR_ARGS(l_err));

                // Capture error
                captureErrorOcmbUpdateCheck(l_err, l_StepError, HWPF_COMP_ID, l_mcc_target);
                encounteredHwpError = true;
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "SUCCESS : p10_omi_init HWP on target HUID 0x%.8x, "
                    "enable scom settings to use inband for all ocmb children",
                    get_huid(l_mcc_target));

                TargetHandleList l_ocmbTargetList;
                getChildAffinityTargets(l_ocmbTargetList , l_mcc_target,
                                        CLASS_CHIP, TYPE_OCMB_CHIP);
                enableInbandScomsOCMB(l_ocmbTargetList);
            }
        } // MCC loop

        // Do not continue if an error was encountered
        if(encounteredHwpError)
        {
            TRACFCOMP( g_trac_isteps_trace,
                INFO_MRK "call_host_omi_init exited early because p10_omi_init "
                "had failures" );
            break;
        }

        // 12.11.c p10_disable_ocmb_i2c.C
        //        - Disable i2c access
        TargetHandleList l_procTargetList;
        getAllChips(l_procTargetList, TYPE_PROC);
        TRACFCOMP(g_trac_isteps_trace,
            "call_host_omi_init: %d PROCs found",
            l_procTargetList.size());

        // We only want to disable i2c if we are in secure mode
        const bool shouldForceDisable = false;

        for ( const auto & l_proc : l_procTargetList )
        {
            TRACFCOMP( g_trac_isteps_trace,
                "p10_disable_ocmb_i2c HWP target HUID 0x%.8x",
                get_huid(l_proc) );

            //  call the HWP with each proc
            fapi2::Target<fapi2::TARGET_TYPE_PROC_CHIP> l_fapi_proc_target
                    (l_proc);

            FAPI_INVOKE_HWP(l_err, p10_disable_ocmb_i2c, l_fapi_proc_target,
                            shouldForceDisable);

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP(g_trac_isteps_trace,
                    "ERROR : call p10_disable_ocmb_i2c HWP(): failed on target "
                    "0x%08X. "
                    TRACE_ERR_FMT,
                    get_huid(l_proc),
                    TRACE_ERR_ARGS(l_err));

                // Once we execute p10_disable_ocmb_i2c on something we won't
                // be able to use the i2c mode to update.
                // Just capture error and don't look to do i2c code update recovery
                captureError(l_err, l_StepError, HWPF_COMP_ID, l_proc);
            }
            else
            {
                TRACFCOMP( g_trac_isteps_trace,
                    "SUCCESS : p10_disable_ocmb_i2c HWP on target HUID 0x%.8x",
                    get_huid(l_proc));
            }
        } // proc loop
    } while(0);

    // Grab informational Explorer logs (early IPL = false)
    EXPSCOM::createExplorerLogs(l_ocmbTargetList, false);

    TRACFCOMP( g_trac_isteps_trace, "call_host_omi_init exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();

}


/**
 * @brief Enable Inband Scom for the OCMB targets
 * @param i_ocmbTargetList - OCMB targets
 */
void enableInbandScomsOCMB( TargetHandleList i_ocmbTargetList )
{
    mutex_t* l_mutex = nullptr;

    for ( const auto & l_ocmb : i_ocmbTargetList )
    {
        //don't mess with attributes without the mutex (just to be safe)
        l_mutex = l_ocmb->getHbMutexAttr<ATTR_IBSCOM_MUTEX>();
        mutex_lock(l_mutex);

        ScomSwitches l_switches = l_ocmb->getAttr<ATTR_SCOM_SWITCHES>();
        l_switches.useI2cScom = 0;
        l_switches.useInbandScom = 1;

        // Modify attribute
        l_ocmb->setAttr<ATTR_SCOM_SWITCHES>(l_switches);
        mutex_unlock(l_mutex);
    }
}

};
