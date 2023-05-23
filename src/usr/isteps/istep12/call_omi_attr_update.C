/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_omi_attr_update.C $               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
 * @file    call_omi_attr_update.C
 *
 *  Support file for Istep 12.2 OMI attribute updates
 *
 */
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>
#include    <istepHelperFuncs.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <sbeio/sbeioif.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <targeting/odyutil.H>

//Fapi Support
#include    <config.h>


using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
void* call_omi_attr_update (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_errl = nullptr;

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_omi_attr_update entry" );
    TargetHandleList l_ocmbChipList;
    getAllChips(l_ocmbChipList, TYPE_OCMB_CHIP, true /* functional only */);

    for(auto l_ocmb : l_ocmbChipList)
    {
        if(!UTIL::isOdysseyChip(l_ocmb))
        {
            continue; // Only push attributes out to Odyssey chips
        }

        l_errl = SBEIO::sendAttrUpdateRequest(l_ocmb);
        if(l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, ERR_MRK"call_omi_attr_update: could not sync attributes");
            captureError(l_errl, l_StepError, ISTEP_COMP_ID, l_ocmb);
            // TODO JIRA: PFHB-443 check for code update on error
        }
        // Still try to push the attributes out to other OCMBs
    }


    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_omi_attr_update exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
