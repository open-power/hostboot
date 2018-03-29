/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_host_p9_fbc_eff_config_links.C $  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2018                        */
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

namespace ISTEP_08
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//*****************************************************************************
// Wrapper function to call host_p9_fbc_eff_config_links
//*****************************************************************************
void* call_host_p9_fbc_eff_config_links( void *io_pArgs )
{
    ISTEP_ERROR::IStepError l_stepError;

    TRACFCOMP(g_trac_isteps_trace,
              ENTER_MRK"call_host_p9_fbc_eff_config_links entry" );

    // Make the FAPI call to p9_fbc_eff_config_links
    // process electrical = true and process optical = false
    fapiHWPCallWrapperHandler(P9_FBC_EFF_CONFIG_LINKS_T_F, l_stepError,
                              HWPF_COMP_ID, TYPE_PROC);

    TRACFCOMP(g_trac_isteps_trace,
              EXIT_MRK"call_host_p9_fbc_eff_config_links exit" );

    return l_stepError.getErrorHandle();
}

};   // end namespace ISTEP_08
