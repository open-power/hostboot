/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_mss_scrub.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>
#include    <util/misc.H>
#include    <diag/prdf/prdfMain.H>


using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;


namespace ISTEP_16
{
void* call_mss_scrub (void *io_pArgs)
{
    IStepError l_stepError;
#if 0
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scrub entry" );

    // There are performance issues and some functional deficiencies
    //  that make runtime scrub problematic, so turning it off
    if( Util::isSimicsRunning() )
    {
        TRACFCOMP(  ISTEPS_TRACE::g_trac_isteps_trace, "Skipping runtime scrub in Simics" );
        return NULL;
    }

    errlHndl_t l_errl = PRDF::startScrub();
    if ( NULL != l_errl )
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Error returned from call to PRDF::startScrub" );

        l_stepError.addErrorDetails( l_errl );

        errlCommit( l_errl, HWPF_COMP_ID );
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_scrub exit" );
#endif
    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
