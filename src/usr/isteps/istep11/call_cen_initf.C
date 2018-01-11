/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep11/call_cen_initf.C $                     */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2018                        */
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
#include    <stdint.h>

#include    <trace/interface.H>
#include    <initservice/taskargs.H>
#include    <errl/errlentry.H>

#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>

#include    <initservice/isteps_trace.H>

#include    <pnor/pnorif.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>

//Fapi Support
#include    <config.h>
#include    <fapi2.H>
#include    <fapi2/plat_hwp_invoker.H>
#include    <util/utilmbox_scratch.H>

// HWP
#include    <cen_initf.H>

using   namespace   ERRORLOG;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   TARGETING;

namespace ISTEP_11
{
void* call_cen_initf (void *io_pArgs)
{
    IStepError l_StepError;
    errlHndl_t l_err = NULL;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_initf entry" );

    do
    {
        TARGETING::TargetHandleList l_membufTargetList;
        getAllChips(l_membufTargetList, TYPE_MEMBUF);

        TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                "call_cen_initf: %d membufs found",
                l_membufTargetList.size());

#ifdef CONFIG_SECUREBOOT
        // only load the hw image if there are membufs present
        if( l_membufTargetList.size() )
        {
            l_err = loadSecureSection(PNOR::CENTAUR_HW_IMG);

            if(l_err)
            {
                // Create IStep error log and cross reference to
                // error that occurred
                l_StepError.addErrorDetails( l_err );

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        ERR_MRK "Failed in call to loadSecureSection "
                        "for section PNOR:CENTAUR_HW_IMG");

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );
                break;
            }
        }
        else
        {
            // no membufs, just exit
            break;
        }
#endif
        for (const auto & l_membuf_target : l_membufTargetList)
        {
            TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                    "cen_initf HWP target HUID %.8x",
                    TARGETING::get_huid(l_membuf_target));

            //  call the HWP with each target
            fapi2::Target <fapi2::TARGET_TYPE_MEMBUF_CHIP> l_fapi_membuf_target
                (l_membuf_target);

            FAPI_INVOKE_HWP(l_err, cen_initf, l_fapi_membuf_target);

            //  process return code.
            if ( l_err )
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "ERROR 0x%.8X:  cen_initf HWP on target HUID %.8x",
                        l_err->reasonCode(),
                        TARGETING::get_huid(l_membuf_target) );

                // capture the target data in the elog
                ErrlUserDetailsTarget(l_membuf_target).addToLog( l_err );

                // Create IStep error log and cross reference the original
                l_StepError.addErrorDetails( l_err );

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );
            }
            else
            {
                TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
                        "SUCCESS :  cen_initf HWP");
            }
        }

#ifdef CONFIG_SECUREBOOT
        if( l_membufTargetList.size() )
        {
            l_err = unloadSecureSection(PNOR::CENTAUR_HW_IMG);

            if(l_err)
            {
                // Create IStep error log and cross reference to error that
                // occurred
                l_StepError.addErrorDetails( l_err );

                TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                        ERR_MRK "Failed in call to unloadSecureSection for "
                        "section PNOR:CENTAUR_HW_IMG");

                // Commit Error
                errlCommit( l_err, ISTEP_COMP_ID );
                break;
            }
        }
#endif

    }while(0);

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace, "call_cen_initf exit" );

    return l_StepError.getErrorHandle();
}

};
