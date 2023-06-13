/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/call_tod_setup.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2023                        */
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
 *  @file call_tod_setup.C
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <targeting/common/targetservice.H>
#include <initservice/initserviceif.H>
#include <isteps/hwpisteperror.H>
#include <arch/magic.H>

#include <tod/TodTrace.H>
#include <tod/TodSvc.H>

using namespace ISTEP_ERROR;

namespace   ISTEP_18
{

void * call_tod_setup(void *dummy)
{
    IStepError l_stepError;
    errlHndl_t l_errl = nullptr;
    TOD_ENTER("call_tod_setup");

    // TODO RTC: 213110 TOD procedures need to be run for eBMC + OP and
    // not run for FSP
    if (!INITSERVICE::spBaseServicesEnabled())
    {
        l_errl = TOD::todSetup();

        if (l_errl)
        {
            TOD_ERR("todSetup() return errl handle "
                    TRACE_ERR_FMT,
                    TRACE_ERR_ARGS(l_errl));
            l_errl->collectTrace("ISTEPS_TRACE");
            //@FIXME-RTC:254475-Remove once this works everywhere
            if( MAGIC_INST_CHECK_FEATURE(MAGIC_FEATURE__IGNORETODFAIL) )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                           "WORKAROUND> Ignoring error for now - TOD::todSetup" );
                l_errl->setSev(ERRORLOG::ERRL_SEV_INFORMATIONAL);
            }
            else
            {
                l_stepError.addErrorDetails( l_errl );
            }
            errlCommit( l_errl, TOD_COMP_ID );
        }
    }

    TOD_EXIT("call_tod_setup");

    return l_stepError.getErrorHandle();
}

}   // end namespace
