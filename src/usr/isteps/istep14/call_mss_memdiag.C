/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep14/call_mss_memdiag.C $                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2016                        */
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
#include <isteps/hwpisteperror.H>
#include <initservice/isteps_trace.H>
#include <targeting/common/utilFilter.H>
#include <diag/attn/attn.H>
#include <diag/mdia/mdia.H>
#include <targeting/namedtarget.H>

using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ERRORLOG;

namespace ISTEP_14
{
void* call_mss_memdiag (void* io_pArgs)
{
    errlHndl_t l_errl = NULL;

    IStepError l_stepError;

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_mss_memdiag entry");

    TARGETING::TargetHandleList l_targetList;
    TARGETING::TYPE targetType;

    // we need to check the model of the master core
    // if it is Cumulus then we will use TYPE_MBA for targetType
    // else it is Nimbus so then we will use TYPE_MCBIST for targetType
    const TARGETING::Target* masterCore = TARGETING::getMasterCore();

    if ( TARGETING::MODEL_CUMULUS ==
         masterCore->getAttr<TARGETING::ATTR_MODEL>() )
    {
        targetType = TARGETING::TYPE_MBA;
    }
    else
    {
        targetType = TARGETING::TYPE_MCBIST;
    }

    getAllChiplets(l_targetList, targetType);

    do
    {
        l_errl = ATTN::startService();
        if( NULL != l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ATTN startService failed");
            break;
        }

        l_errl = MDIA::runStep(l_targetList);
        if( NULL != l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace, "MDIA subStep failed");
            break;
        }

        l_errl = ATTN::stopService();
        if( NULL != l_errl )
        {
            TRACFCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
                      "ATTN stopService failed");
            break;
        }

    }while( 0 );

    if( NULL != l_errl )
    {
        // Create IStep error log and cross reference to error that occurred
        l_stepError.addErrorDetails(l_errl);

        // Commit Error
        errlCommit(l_errl, HWPF_COMP_ID);
    }

    TRACDCOMP(ISTEPS_TRACE::g_trac_isteps_trace,
              "call_mss_memdiag exit");

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};
