/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/errl/errludstate.C $                                  */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2017,2018                        */
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
 *  @file errludsysstate.C
 *
 *  @brief Implementation of ErrlUserDetailsSysState
 */
#include <errl/errludstate.H>
#include <errl/errlreasoncodes.H>
#include <initservice/initserviceif.H>

namespace ERRORLOG
{

    ErrlUserDetailsSysState::ErrlUserDetailsSysState()
    {
        //***** Memory Layout *****
        // 1 bytes  : Major Istep
        // 1 bytes  : Minor Istep
        const size_t TOTAL_SIZE = 2;

        uint8_t l_iStep = 0;
        uint8_t l_subStep = 0;

#ifndef __HOSTBOOT_RUNTIME
        INITSERVICE::GetIstepData( l_iStep,
                                   l_subStep );
#endif

        uint8_t* l_buf = reinterpret_cast<uint8_t*>(
                            reallocUsrBuf(TOTAL_SIZE));
        memset( l_buf, 0, TOTAL_SIZE );
        l_buf[0] = l_iStep;
        l_buf[1] = l_subStep;

        // Set up ErrlUserDetails instance variables
        iv_CompId = ERRL_COMP_ID;
        iv_Version = 1;
        iv_SubSection = ERRL_UDT_SYSSTATE;
    }

    ErrlUserDetailsSysState::~ErrlUserDetailsSysState()
    {

    }
}
