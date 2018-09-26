/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep16/call_host_load_io_ppe.C $              */
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

#include    <errl/errlentry.H>
#include    <initservice/isteps_trace.H>
#include    <isteps/hwpisteperror.H>
#include    <errl/errludtarget.H>
#include    <errl/errlmanager.H>

//  targeting support
#include    <targeting/common/commontargeting.H>
#include    <targeting/common/utilFilter.H>
#include    <fapi2/target.H>
#include    <fapi2/plat_hwp_invoker.H>

// isSMPWrapConfig call support
#include <initservice/initserviceif.H>

//  HWP call support
#include <nest/nestHwpHelperFuncs.H>   // fapiHWPCallWrapperForChip

using   namespace   ERRORLOG;
using   namespace   TARGETING;
using   namespace   ISTEP;
using   namespace   ISTEP_ERROR;
using   namespace   fapi2;

namespace ISTEP_16
{

void* call_host_load_io_ppe (void *io_pArgs)
{
    IStepError  l_stepError;
    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_load_io_ppe entry" );
    do
    {
        if (!INITSERVICE::isSMPWrapConfig())
        {
            // Make call to p9_io_obus_image_build
            fapiHWPCallWrapperHandler(P9_IO_OBUS_IMAGE_BUILD, l_stepError,
                                      HWPF_COMP_ID, TYPE_OBUS)               &&
            // Make call to p9_io_xbus_image_build
            fapiHWPCallWrapperHandler(P9_IO_XBUS_IMAGE_BUILD, l_stepError,
                                      HWPF_COMP_ID, TYPE_PROC);
        }

    } while( 0 );

    TRACFCOMP( ISTEPS_TRACE::g_trac_isteps_trace,
               "host_load_io_ppe exit ");

    return l_stepError.getErrorHandle();
}


};
