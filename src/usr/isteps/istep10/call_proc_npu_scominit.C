/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_npu_scominit.C $             */
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
/**
   @file call_proc_npu_scominit.C
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

//  Component ID support
#include <hbotcompid.H>                // HWPF_COMP_ID

//  TARGETING support
#include <attributeenums.H>            // TYPE_PROC

//  Error handling support
#include <isteps/hwpisteperror.H>      // ISTEP_ERROR::IStepError

//  Tracing support
#include <trace/interface.H>           // TRACFCOMP
#include <initservice/isteps_trace.H>  // g_trac_isteps_trace

//  HWP call support
#include <nest/nestHwpHelperFuncs.H>   // fapiHWPCallWrapperForChip

namespace ISTEP_10
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//******************************************************************************
// Wrapper function to call proc_npu_scominit
//******************************************************************************
void* call_proc_npu_scominit( void *io_pArgs )
{
    IStepError l_stepError;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_npu_scominit entry");

#ifndef CONFIG_SMP_WRAP_TEST
    // Make the FAPI call to p9_npu_scominit
    fapiHWPCallWrapperHandler(P9_NPU_SCOMINIT, l_stepError,
                              HWPF_COMP_ID, TYPE_PROC);
#endif

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_npu_scominit exit");

    return l_stepError.getErrorHandle();
}
};   // end namespace ISTEP_10
