/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep06/call_host_update_master_tpm.C $        */
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

#include <stdint.h>
#include <trace/interface.H>
#include <errl/errlentry.H>
#include <errl/errlmanager.H>
#include <isteps/hwpisteperror.H>
#include <trustedbootif.H>

namespace ISTEP_06
{

void* call_host_update_master_tpm( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_stepError;

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_update_master_tpm entry" );

#ifdef CONFIG_TPMDD
    errlHndl_t l_err = NULL;
    // Initialize the master TPM
    l_err = (errlHndl_t)TRUSTEDBOOT::host_update_master_tpm(io_pArgs);
    if (l_err)
    {
        l_stepError.addErrorDetails(l_err);
        errlCommit( l_err, SECURE_COMP_ID );
    }
#endif

    TRACDCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "call_host_update_master_tpm exit" );

    return l_stepError.getErrorHandle();
}

};
