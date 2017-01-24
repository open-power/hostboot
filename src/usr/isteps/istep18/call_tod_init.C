/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/call_tod_init.C $                      */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2017                        */
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

#include "TodTrace.H"
#include "TodSvc.H"

using namespace ISTEP_ERROR;

namespace   ISTEP_18
{

void * call_tod_init(void *dummy)
{
    IStepError l_stepError;
    errlHndl_t l_errl = NULL;
    TOD_ENTER("call_tod_init");

    if (!INITSERVICE::spBaseServicesEnabled())
    {
        l_errl = TOD::todInit();

        if (l_errl)
        {
            l_stepError.addErrorDetails( l_errl );
            TOD_ERR("todInit() return errl handle %p", l_errl);
            errlCommit( l_errl, TOD_COMP_ID );
        }
    }
    return l_stepError.getErrorHandle();
}

}   // end namespace
