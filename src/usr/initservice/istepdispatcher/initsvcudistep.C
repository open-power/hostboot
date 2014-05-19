/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/initservice/istepdispatcher/initsvcudistep.C $        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
 *  @file initsvcudistep.C
 *
 *  @brief Implementation of InitSvcUserDetailsIstep
 */
#include <initservice/initsvcudistep.H>
#include <initservice/initsvcreasoncodes.H>

namespace   INITSERVICE
{

//------------------------------------------------------------------------------
InitSvcUserDetailsIstep::InitSvcUserDetailsIstep(
    const char * i_pIstepname,
    const uint16_t i_step,
    const uint16_t i_substep)
{
    InitSvcUserDetailsIstepData * l_pBuf =
        reinterpret_cast<InitSvcUserDetailsIstepData *>(
            reallocUsrBuf(sizeof(InitSvcUserDetailsIstepData) +
                          (strlen(i_pIstepname) + 1)));

    l_pBuf->iv_step = i_step;
    l_pBuf->iv_substep = i_substep;
    strcpy(l_pBuf->iv_pIstepname, i_pIstepname);

    // Set up ErrlUserDetails instance variables
    iv_CompId = INITSVC_COMP_ID;
    iv_Version = 1;
    iv_SubSection = INIT_SVC_UDT_ISTEP;
}

//------------------------------------------------------------------------------
InitSvcUserDetailsIstep::~InitSvcUserDetailsIstep()
{

}

}

