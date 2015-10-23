/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_enable_osclite.C $           */
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
   @file call_proc_enable_osclite.C
 *
 *  Support file for IStep: nest_chiplets
 *   Nest Chiplets
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

#include    <isteps/hwpisteperror.H>

#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>
#include    <initservice/initserviceif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//  MVPD
#include <devicefw/userif.H>
#include <vpd/mvpdenums.H>

#include <config.h>

//  --  prototype   includes    --
//  Add any customized routines that you don't want overwritten into
//      "start_clocks_on_nest_chiplets_custom.C" and include
//      the prototypes here.
//  #include    "nest_chiplets_custom.H"
namespace   ISTEP_08
{

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;

//*****************************************************************************
// wrapper function to call proc_enable_osclite
//*****************************************************************************
void* call_proc_enable_osclite(void *io_pArgs)
{
    errlHndl_t l_errl = NULL;
    IStepError  l_stepError;
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_enable_osclite" );

    //@TODO RTC:134078
    //call p9_enable_osclite
    //Cumulus only
    //FAPI_INVOKE_HWP(l_errl,p9_enable_osclite);
    if(l_errl)
    {
        l_stepError.addErrorDetails(l_errl);
        errlCommit(l_errl, HWPF_COMP_ID);
    }
    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_proc_enable_osclite" );
    return l_stepError.getErrorHandle();
}
};
