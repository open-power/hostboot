/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_host_startprd_pbus.C $            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2015                        */
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

/**
 *  @file edi_ei_initialization.C
 *
 *  Support file for IStep: edi_ei_initialization
 *   EDI, EI Initialization
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include    <stdint.h>
#include    <map>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <hwas/common/deconfigGard.H>
#include    <hwas/common/hwasCommon.H>

#include    <sbe/sbeif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/common/trace.H>

#include    <diag/prdf/prdfMain.H>

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
    #include    <occ/occ_common.H>
#endif

namespace   ISTEP_09
{


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   HWAS;


//
//  Wrapper function to call host_startprd_pbus
//
void*    call_host_startprd_pbus( void    *io_pArgs )
{
    errlHndl_t  l_errl  =   NULL;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_startprd_pbus entry" );

    do
    {
        //@TODO RTC:134079
        //l_errl = PRDF::initialize();
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Error returned from call to PRDF::initialize");
            break;
        }

        // Perform calculated deconfiguration of procs based on
        // bus endpoint deconfigurations, and perform SMP node
        // balancing
        l_errl = HWAS::theDeconfigGard().deconfigureAssocProc();
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Error returned from call to "
                    "HWAS::theDeconfigGard().deconfigureAssocProc");
            break;
        }

#ifdef CONFIG_ENABLE_CHECKSTOP_ANALYSIS
        // update firdata inputs for OCC
        TARGETING::Target* masterproc = NULL;
        TARGETING::targetService().masterProcChipTargetHandle(masterproc);
        l_errl = HBOCC::loadHostDataToSRAM(masterproc,
                                            PRDF::ALL_PROC_MASTER_CORE);
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "Error returned from call to HBOCC::loadHostDataToSRAM");
            break;
        }
#endif

    }while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
           "call_host_startprd_pbus exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_errl;
}
};
