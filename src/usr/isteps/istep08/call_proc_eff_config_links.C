/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep08/call_proc_eff_config_links.C $         */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2016,2020                        */
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
   @file call_proc_eff_config_links.C
 *
 *  Support file for IStep: proc_eff_config_links
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

#include <hbotcompid.H>           // HWPF_COMP_ID
#include <attributeenums.H>       // TYPE_PROC
#include <isteps/hwpisteperror.H> //ISTEP_ERROR:IStepError
#include <istepHelperFuncs.H>     // captureError
#include <fapi2/plat_hwp_invoker.H>
#include <nest/nestHwpHelperFuncs.H>

namespace ISTEP_08
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//*****************************************************************************
// Wrapper function to call p10_fbc_eff_config_links
//*****************************************************************************
void* call_proc_eff_config_links( void *io_pArgs )
{
    IStepError l_stepError;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_eff_config_links");

    // Make the FAPI call to p10_fbc_eff_config_links
    fapiHWPCallWrapperHandler(P10_FBC_EFF_CONFIG_LINKS_ELECTRICAL, l_stepError,
                              HWPF_COMP_ID, TYPE_PROC);

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_eff_config_links");
    return l_stepError.getErrorHandle();
}

};   // end namespace ISTEP_08
