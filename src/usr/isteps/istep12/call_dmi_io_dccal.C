/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep12/call_dmi_io_dccal.C $                  */
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
#include    <errl/errlentry.H>
#include    <errl/errlmanager.H>
#include    <initservice/isteps_trace.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

//  targeting support.
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;
using   namespace   TARGETING;


namespace ISTEP_12
{
void* call_dmi_io_dccal (void *io_pArgs)
{
    ISTEP_ERROR::IStepError l_StepError;
    //@TODO RTC:133831
#if 0
    errlHndl_t  l_errl  =   NULL;

    // We are not running this analog procedure in VPO
    if (TARGETING::is_vpo())
    {
        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                   "Skip dmi_io_dccal in VPO!");
        return l_StepError.getErrorHandle();
    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_dmi_io_dccal entry" );

    TargetPairs_t l_dmi_io_dccal_targets;
    get_dmi_io_targets(l_dmi_io_dccal_targets);


    // Note:
    // Due to lab tester board environment, HW procedure writer (Varkey) has
    // requested to send in one target of a time (we used to send in
    // the MCS and MEMBUF pair in one call). Even though they don't have to be
    // in order, we should keep the pair concept here in case we need to send
    // in a pair in the future again.
    for (TargetPairs_t::const_iterator
         l_itr = l_dmi_io_dccal_targets.begin();
         l_itr != l_dmi_io_dccal_targets.end();
         ++l_itr)
    {
        /*
         //@TODO RTC:133831
        const fapi::Target l_fapi_mcs_target( TARGET_TYPE_MCS_CHIPLET,
                (const_cast<TARGETING::Target*>(l_itr->first)));

        const fapi::Target l_fapi_membuf_target( TARGET_TYPE_MEMBUF_CHIP,
                (const_cast<TARGETING::Target*>(l_itr->second)));

        TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                "===== Call dmi_io_dccal HWP( mcs 0x%.8X, mem 0x%.8X) : ",
                TARGETING::get_huid(l_itr->first),
                TARGETING::get_huid(l_itr->second));

        // Call on the MCS
        FAPI_INVOKE_HWP(l_errl, dmi_io_dccal, l_fapi_mcs_target);
        */
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X :  dmi_io_dccal HWP Target MCS 0x%.8X",
                      l_errl->reasonCode(), TARGETING::get_huid(l_itr->first));

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
            // We want to continue the training despite the error, so
            // no break
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_dmi_io_dccal HWP - Target 0x%.8X",
                    TARGETING::get_huid(l_itr->first));
        }

        // io_dccal.C is going to look for a PLL ring with a "stub"
        // mem freq -- so set to a default, then clear it (so as not
        // to mess up MSS HWP later
        //@TODO RTC:133831
        /*
        TARGETING::Target* l_membuf_target =
            (const_cast<TARGETING::Target*>(l_itr->second));
        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(1600);

        // Call on the MEMBUF
        FAPI_INVOKE_HWP(l_errl, dmi_io_dccal, l_fapi_membuf_target);

        // Clear MSS_FREQ.  This attribute will be set in istep 12 (mss_freq) for good
        l_membuf_target->setAttr<TARGETING::ATTR_MSS_FREQ>(0);
        */
        if (l_errl)
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ERROR 0x%.8X :  dmi_io_dccal HWP Target Membuf 0x%.8X",
                      l_errl->reasonCode(), TARGETING::get_huid(l_itr->second));

            // Create IStep error log and cross reference error that occurred
            l_StepError.addErrorDetails( l_errl );

            // Commit Error
            errlCommit( l_errl, HWPF_COMP_ID );
            // We want to continue the training despite the error, so
            // no break
        }
        else
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "SUCCESS :  call_dmi_io_dccal HWP - Target 0x%.8X",
                    TARGETING::get_huid(l_itr->second));
        }

    }

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_dmi_io_dccal exit" );
#endif
    // end task, returning any errorlogs to IStepDisp
    return l_StepError.getErrorHandle();
}

};
