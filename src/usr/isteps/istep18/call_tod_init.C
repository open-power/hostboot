/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/call_tod_init.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2021                        */
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
 *  @file call_tod_init.C
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
#include <htmgt_memthrottles.H>

#include <tod/TodTrace.H>
#include <tod/TodSvc.H>

using namespace ISTEP_ERROR;

namespace   ISTEP_18
{

void * call_tod_init(void *dummy)
{
    IStepError l_stepError;
    errlHndl_t l_errl = nullptr;
    TOD_ENTER("call_tod_init");

    // TODO RTC: 213110 TOD procedures need to be run for eBMC + OP and
    // not run for FSP
    if (!INITSERVICE::spBaseServicesEnabled())
    {
        l_errl = TOD::todInit();

        if (l_errl)
        {
            TOD_ERR("todInit() return errl handle ",
                    TRACE_ERR_FMT,
                    TRACE_ERR_ARGS(l_errl));
            l_errl->collectTrace("ISTEPS_TRACE");
            l_stepError.addErrorDetails( l_errl );
            errlCommit(l_errl, TOD_COMP_ID);
        }

#ifndef CONFIG_FSP_BUILD
        // HTMGT: Memory throttle calculations
        TOD_INF("calling HTMGT:calcMemThrottles");
        l_errl = HTMGT::calcMemThrottles();
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      ERR_MRK"HTMGT::calcMemThrottles() return errl handle ",
                      TRACE_ERR_FMT,
                      TRACE_ERR_ARGS(l_errl));
            l_errl->collectTrace("ISTEPS_TRACE");
            // Don't stop IPL (skip lstepError.addErrorDetails() call)
            errlCommit(l_errl, TOD_COMP_ID);
        }
#endif
    }

    TOD_EXIT("call_tod_init");

    return l_stepError.getErrorHandle();
}

}   // end namespace
