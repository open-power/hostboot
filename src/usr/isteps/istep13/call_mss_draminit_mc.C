/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep13/call_mss_draminit_mc.C $               */
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
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <errl/errludtarget.H>
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>

//  targeting support
#include <targeting/common/commontargeting.H>
#include <targeting/common/util.H>
#include <targeting/common/utilFilter.H>
#include "istep13consts.H"

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_13
{
void* call_mss_draminit_mc (void *io_pArgs)
{
    errlHndl_t l_err = NULL;

    IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,"call_mss_draminit_mc entry" );

    // Get all centaur targets
    TARGETING::TargetHandleList l_mBufTargetList;
    getAllChips(l_mBufTargetList, TYPE_MEMBUF);

    // Limit the number of MBAs to run in VPO environment to save time.
    uint8_t l_memBufLimit = l_mBufTargetList.size();
    if (TARGETING::is_vpo() && (VPO_NUM_OF_MEMBUF_TO_RUN < l_memBufLimit))
    {
        l_memBufLimit = VPO_NUM_OF_MEMBUF_TO_RUN;
    }

    for ( uint8_t l_mBufNum=0; l_mBufNum < l_memBufLimit; l_mBufNum++ )
    {
        const TARGETING::Target* l_membuf_target = l_mBufTargetList[l_mBufNum];

        // Dump current run on target
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "Running mss_draminit_mc HWP on "
                "target HUID %.8X", TARGETING::get_huid(l_membuf_target));

        //@TODO RTC:133831 Cast to a fapi target
        //fapi::Target l_fapi_membuf_target( TARGET_TYPE_MEMBUF_CHIP,
        //        (const_cast<TARGETING::Target*>(l_membuf_target)) );

        //  call the HWP with each fapi::Target
        //FAPI_INVOKE_HWP(l_err, mss_draminit_mc, l_fapi_membuf_target);

        if (l_err)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                    "ERROR 0x%.8X : mss_draminit_mc HWP returns error",
                    l_err->reasonCode());

            // capture the target data in the elog
            ErrlUserDetailsTarget(l_membuf_target).addToLog( l_err );

            // Create IStep error log and cross reference to error that occurred
            l_stepError.addErrorDetails( l_err );

            // Commit Error
            errlCommit( l_err, HWPF_COMP_ID );
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  mss_draminit_mc HWP( )" );
        }

    } // End; memBuf loop

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_mss_draminit_mc exit" );

    return l_stepError.getErrorHandle();
}

};
