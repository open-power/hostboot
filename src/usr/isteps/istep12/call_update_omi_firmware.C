/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_update_omi_firmware.C $           */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2020                             */
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
 * @file    call_update_omi_firmware.C
 *
 *  Support file for Istep 12.12 Explorer firmware update
 *
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

// Targeting support
#include    <targeting/targplatutil.H>

#include    <expupd/expupd.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;
using   namespace   ISTEPS_TRACE;

namespace ISTEP_12
{
void* call_update_omi_firmware (void *io_pArgs)
{
    IStepError l_StepError;
    TRACFCOMP( g_trac_isteps_trace, "call_update_omi_firmware entry" );

    // Check if any explorer chips require a firmware update and update them
    // (skipped on MPIPL)
    if (UTIL::assertGetToplevelTarget()->getAttr<ATTR_IS_MPIPL_HB>())
    {
        TRACFCOMP( g_trac_isteps_trace,
                   "skipping expupd::UpdateAll() due to MPIPL");
    }
    else
    {
        expupd::updateAll(l_StepError);
    }

    TRACFCOMP( g_trac_isteps_trace, "call_update_omi_firmware exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();

}

};
