/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep09/call_fabric_pre_trainadv.C $           */
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
 *  @file call_fabric_pre_trainadv.C
 *
 *  Support file for IStep: edi_ei_initialization
 *   EDI, EI Initialization
 *
 *  HWP_IGNORE_VERSION_CHECK
 *
 */

/******************************************************************************/
// Includes
/******************************************************************************/

//  Integral and component ID support
#include <stdint.h>                     // uint32_t
#include <hbotcompid.H>                 // HWPF_COMP_ID

//  Tracing support
#include <trace/interface.H>            // TRACFCOMP
#include <initservice/isteps_trace.H>   // g_trac_isteps_trace
#include <initservice/initserviceif.H>  // isSMPWrapConfig

//  Error handling support
#include <errl/errlentry.H>             // errlHndl_t
#include <isteps/hwpisteperror.H>       // IStepError

//  Pbus link service support
#include <pbusLinkSvc.H>                // TargetPairs_t, PbusLinkSvc

//  HWP call support
#include <istepHelperFuncs.H>           // captureError
#include <istep09/istep09HelperFuncs.H> // trainBusHandler

namespace   ISTEP_09
{
using   namespace   ISTEP_ERROR;
using   namespace   ISTEPS_TRACE;
using   namespace   TARGETING;

//******************************************************************************
// Wrapper function to call fabric_pre_trainadv
//******************************************************************************
void* call_fabric_pre_trainadv( void *io_pArgs )
{
    errlHndl_t  l_err(nullptr);
    IStepError  l_stepError;

    TRACFCOMP(g_trac_isteps_trace, ENTER_MRK"call_fabric_pre_trainadv entry" );

    EDI_EI_INITIALIZATION::TargetPairs_t l_pbusConnections;
    TYPE l_busSet[] = { TYPE_XBUS, TYPE_OBUS };
    constexpr uint32_t l_maxBusSet = sizeof(l_busSet)/sizeof(TYPE);

    for (uint32_t ii = 0; (!l_err) && (ii < l_maxBusSet); ii++)
    {
        l_err = EDI_EI_INITIALIZATION::PbusLinkSvc::getTheInstance().
                    getPbusConnections(l_pbusConnections, l_busSet[ii]);

        if (l_err)
        {
            TRACFCOMP(g_trac_isteps_trace,
                "ERROR 0x%.8X : getPbusConnections TYPE_%cBUS returns error",
                l_err->reasonCode(), (ii ? 'O':'X') );

            // Capture error and then exit
            captureError(l_err,
                         l_stepError,
                         HWPF_COMP_ID);

            // Don't continue with a potential bad connection set
            break;
        }

        if (TYPE_XBUS == l_busSet[ii])
        {
            // Make the FAPI call to p9_io_xbus_pre_trainadv
            if (!trainBusHandler(l_busSet[ii],
                                 P9_IO_XBUS_PRE_TRAINADV,
                                 l_stepError,
                                 HWPF_COMP_ID,
                                 l_pbusConnections))
            {
                break;
            }
        }  // end if (TYPE_XBUS == l_busSet[ii])
        else if (INITSERVICE::isSMPWrapConfig() &&
                (TYPE_OBUS == l_busSet[ii]))
        {
            // Make the FAPI call to p9_io_obus_pre_trainadv
            if (!trainBusHandler(l_busSet[ii],
                                 P9_IO_OBUS_PRE_TRAINADV,
                                 l_stepError,
                                 HWPF_COMP_ID,
                                 l_pbusConnections))
            {
                break;
            }
        }  // end else if (TYPE_OBUS == l_busSet[ii])
    } // end for (uint32_t ii = 0; (!l_err) && (ii < l_maxBusSet); ii++)

    TRACFCOMP(g_trac_isteps_trace, EXIT_MRK"call_fabric_pre_trainadv exit" );

    // end task, returning any errorlogs to IStepDisp
    return l_stepError.getErrorHandle();
}

};  // end namespace   ISTEP_09
