/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_setup_sbe.C $                */
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
/**
 *  @file call_host_setup_sbe.C
 *
 *  Support file for IStep: slave_sbe
 *   Slave SBE
 *
 *  HWP_IGNORE_VERSION_CHECK
 */

/******************************************************************************/
// Includes
/******************************************************************************/
#include <stdint.h>
#include <trace/interface.H>
#include <initservice/taskargs.H>
#include <errl/errlentry.H>
#include <initservice/isteps_trace.H>
#include <initservice/initserviceif.H>
#include <initservice/initsvcreasoncodes.H>
#include <sys/time.h>
#include <devicefw/userif.H>
#include <i2c/i2cif.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/utilFilter.H>
#include <targeting/namedtarget.H>
#include <targeting/attrsync.H>

#include <isteps/hwpisteperror.H>

#include <errl/errludtarget.H>

using namespace ISTEP;
using namespace ISTEP_ERROR;
using namespace ERRORLOG;
using namespace TARGETING;

namespace ISTEP_08
{

//******************************************************************************
// call_host_setup_sbe()
//******************************************************************************
void* call_host_setup_sbe(void *io_pArgs)
{
    errlHndl_t l_errl = NULL;
    IStepError  l_stepError;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_setup_sbe entry" );

    //@TODO RTC:134078
    //call host_setup_sbe
    //FAPI_INVOKE_HWP(l_errl,p9_set_fsi_gp_shadow);
    if(l_errl)
    {
        l_stepError.addErrorDetails(l_errl);
        errlCommit(l_errl, HWPF_COMP_ID);
    }
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_setup_sbe exit" );
    return l_stepError.getErrorHandle();
}
};
