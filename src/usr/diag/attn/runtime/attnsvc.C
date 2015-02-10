/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/attn/runtime/attnsvc.C $                         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2014,2015                        */
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
 * @file attnsvc.C
 *
 * @brief HBRT ATTN background service class function definitions.
 */

#include <errl/errlmanager.H>
#include "runtime/attnsvc.H"
#include "common/attntrace.H"
#include "common/attnprd.H"
#include "common/attnproc.H"
#include "common/attnmem.H"
#include "common/attntarget.H"

using namespace std;
using namespace PRDF;
using namespace TARGETING;
using namespace ERRORLOG;

namespace ATTN
{

errlHndl_t Service::disableAttns()
{
    ATTN_SLOW("Service::disableAttns() enter");
    // During runtime do nothing.
    ATTN_SLOW("Service::disableAttns() exit");

    return NULL;
}

errlHndl_t Service::enableAttns()
{
    ATTN_SLOW("Service::enableAttns() enter");

    errlHndl_t err = configureInterrupts(UP);

    ATTN_SLOW("Service::enableAttns() exit");

    return err;
}

Service::~Service()
{
    ATTN_SLOW("Service::~Service() enter");
    errlHndl_t err = disableAttns();

    if(err)
    {
        errlCommit(err, ATTN_COMP_ID);
    }
    ATTN_SLOW("Service::~Service() exit");
}

}
