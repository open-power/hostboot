/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/hwpf/hwp/dram_initialization/dram_initialization.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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
 *  @file dram_initialization.C
 *
 *  Support file for IStep: dram_initialization
 *   Dram Initialization
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <errl/errludtarget.H>
#include    <diag/mdia/mdia.H>
#include    <diag/attn/attn.H>
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <intr/interrupt.H>    // for PIR_t structure

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/util.H>
#include    <targeting/common/utilFilter.H>

//  fapi support
#include    <fapi.H>
#include    <fapiPlatHwpInvoker.H>
#include    <isteps/hwpf_reasoncodes.H>

#include    "dram_initialization.H"
#include    <pbusLinkSvc.H>

//  Uncomment these files as they become available:
// #include    "host_startPRD_dram/host_startPRD_dram.H"
#include    "host_mpipl_service/proc_mpipl_ex_cleanup.H"
#include    "host_mpipl_service/proc_mpipl_chip_cleanup.H"
#include    "mss_extent_setup/mss_extent_setup.H"
// #include    "mss_memdiag/mss_memdiag.H"
// #include    "mss_scrub/mss_scrub.H"
#include    "mss_thermal_init/mss_thermal_init.H"
#include    "proc_setup_bars/mss_setup_bars.H"
#include    "proc_setup_bars/proc_setup_bars.H"
#include    "proc_pcie_config/proc_pcie_config.H"
#include    "proc_exit_cache_contained/proc_exit_cache_contained.H"
#include    "mss_power_cleanup/mss_power_cleanup.H"
#include    "proc_throttle_sync/proc_throttle_sync.H"
//remove these once memory setup workaround is removed
#include <devicefw/driverif.H>
#include <vpd/spdenums.H>
#include <sys/time.h>
#include <sys/mm.h>
#include <dump/dumpif.H>
#include <vfs/vfs.H>

#ifdef CONFIG_IPLTIME_CHECKSTOP_ANALYSIS
    #include    <occ/occ_common.H>
#endif

namespace   DRAM_INITIALIZATION
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   EDI_EI_INITIALIZATION;
using   namespace   fapi;
using   namespace   ERRORLOG;

//
//  Wrapper function to call mss_extent_setup
//
void*    call_mss_extent_setup( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    IStepError  l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_extent_setup entry" );

    //  call the HWP
    FAPI_INVOKE_HWP( l_errl, mss_extent_setup );

    if ( l_errl )
    {
        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "ERROR : failed executing mss_extent_setup returning error" );

        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails( l_errl );

        // Commit Error
        errlCommit( l_errl, HWPF_COMP_ID );
    }
    else
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "SUCCESS : mss_extent_setup completed ok" );
    }


    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
            "call_mss_extent_setup exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};   // end namespace
