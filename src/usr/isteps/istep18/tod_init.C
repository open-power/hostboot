/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep18/tod_init.C $                           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016                             */
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
 *  @file tod_init.C
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

#include "TodTrace.H"
// @TODO RTC:149253
//#include "tod_init.H"
//#include "TodSvc.H"

namespace   ISTEP_18
{

void * call_tod_setup(void *dummy)
{
    errlHndl_t l_errl = NULL;

    TOD_ENTER("call_tod_setup");
//    //@TODO RTC:149253 uncomment
//    if (!INITSERVICE::spBaseServicesEnabled())
//    {
//        l_errl = TOD::TodSvc::getTheInstance().todSetup();
//
//        if (l_errl)
//        {
//            TOD_ERR("todSetup() return errl handle %p", l_errl);
//            errlCommit( l_errl, TOD_COMP_ID );
//        }
//    }

    return l_errl; // //@TODO RTC:149253 update later
}

void * call_tod_init(void *dummy)
{
    errlHndl_t l_errl = NULL;
    TOD_ENTER("call_init");

//    // @TODO RTC:149253
//    if (!INITSERVICE::spBaseServicesEnabled())
//    {
//        l_errl = TOD::TodSvc::getTheInstance().todInit();
//
//        if (l_errl)
//        {
//            TOD_ERR("todInit() return errl handle %p", l_errl);
//            errlCommit( l_errl, TOD_COMP_ID );
//        }
//    }

    return l_errl; //@TODO RTC:149253 update later
}

};   // end namespace
