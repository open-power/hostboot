/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/istep124/call_ody_omi_hss_ppe_start.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015,2023                        */
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
 * @file    call_ody_omi_hss_ppe_start.C
 *
 *  Support file for Istep 124.03 Odyssey specific inits
 *
 */
#include    <errl/errlentry.H>
#include    <ocmbupd_helpers.H>
#include    <isteps/istepmasterlist.H>

using   namespace   ISTEP;
using   namespace   ISTEP_12;
using   namespace   ISTEPS_TRACE;
using   namespace   ERRORLOG;

#define CONTEXT call_ody_omi_hss_ppe_start

namespace ISTEP_12
{

void* call_ody_omi_hss_ppe_start (void *io_pArgs)
{
    TRACISTEP(ENTER_MRK"call_ody_omi_hss_ppe_start");

    errlHndl_t l_err = nullptr;
    l_err = run_ocmb_omi_scominit(ODY_OMI_HSS_START_PPE);

    TRACISTEP(EXIT_MRK"call_ody_omi_hss_ppe_start");

    return l_err;
}

};
