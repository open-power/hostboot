/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/isteps/hwpistepud.C $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2015                             */
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
 *  @file hwpudistep.C
 *
 *  @brief Implementation of HwpSvcUserDetailsIstep
 */
#include <hbotcompid.H>
#include <isteps/hwpistepud.H>
#include <hwpf/hwpf_reasoncodes.H>

using namespace ISTEP_ERROR;

//------------------------------------------------------------------------------
HwpUserDetailsIstep::HwpUserDetailsIstep( errlHndl_t i_err )
{
    HwpUserDetailsIstepErrorData * l_pBuf =
        reinterpret_cast<HwpUserDetailsIstepErrorData *>(
                reallocUsrBuf(sizeof(HwpUserDetailsIstepErrorData)));

    l_pBuf->eid = i_err->eid();

    l_pBuf->reasoncode = i_err->reasonCode();

    // Set up ErrlUserDetails instance variables
    iv_CompId = HWPF_COMP_ID;
    iv_Version = 1;
    iv_SubSection = fapi::HWPF_UDT_STEP_ERROR_DETAILS;
}

//------------------------------------------------------------------------------
HwpUserDetailsIstep::~HwpUserDetailsIstep()
{

}


