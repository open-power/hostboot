/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep10/call_proc_chiplet_scominit.C $         */
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
   @file call_proc_chiplet_scominit.C
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
#include <istepHelperFuncs.H>          // captureError

//  Tracing support
#include <trace/interface.H>           // TRACFCOMP
#include <initservice/isteps_trace.H>  // g_trac_isteps_trace
#include <initservice/initserviceif.H>  // isSMPWrapConfig
//  HWP call support
#include <nest/nestHwpHelperFuncs.H>   // fapiHWPCallWrapperForChip

// Util TCE Support
#include <util/utiltce.H>              // TCE::utilUseTcesForDmas

namespace ISTEP_10
{
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//******************************************************************************
// Wrapper function to call proc_chiplet_scominit
//******************************************************************************
void* call_proc_chiplet_scominit( void *io_pArgs )
{
    errlHndl_t l_err(nullptr);
    IStepError l_stepError;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_proc_chiplet_scominit entry" );

    if (!INITSERVICE::isSMPWrapConfig())
    {
        // Make the FAPI call to p9_chiplet_scominit
        // Make the FAPI call to p9_io_obus_firmask_save_restore, if previous call succeeded
        // Make the FAPI call to p9_psi_scominit, if previous call succeeded
        fapiHWPCallWrapperHandler(P9_CHIPLET_SCOMINIT, l_stepError,
                                  HWPF_COMP_ID, TYPE_PROC)                &&
        fapiHWPCallWrapperHandler(P9_OBUS_FIRMASK_SAVE_RESTORE, l_stepError,
                                  HWPF_COMP_ID, TYPE_PROC)                &&
        fapiHWPCallWrapperHandler(P9_PSI_SCOMINIT, l_stepError,
                                  HWPF_COMP_ID, TYPE_PROC);
    }

    // Enable TCEs with an empty TCE Table, if necessary
    // This will prevent the FSP from DMAing to system memory without
    // hostboot's knowledge
    if ( TCE::utilUseTcesForDmas() )
    {
        l_err = TCE::utilEnableTcesWithoutTceTable();

        if (l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                      "call_proc_chiplet_scominit: "
                      "utilEnableTcesWithoutTceTable, returned ERROR 0x%.4X",
                      l_err->reasonCode());

            // Capture error
            captureError(l_err,
                         l_stepError,
                         HWPF_COMP_ID);
        }
    }

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_proc_chiplet_scominit exit" );

    return l_stepError.getErrorHandle();
}
};   // end namespace ISTEP_10
