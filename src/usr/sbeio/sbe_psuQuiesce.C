/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_psuQuiesce.C $                              */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2017                        */
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
* @file sbe_psuQuiesce.C
* @brief Send command to quiesce the SBE
*/

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
TRACDCOMP(g_trac_sbeio,"psuQuiesce: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
TRACFCOMP(g_trac_sbeio,"psuQuiesce: " printf_string,##args)

namespace SBEIO
{

    /**
     * @brief Sends a PSU chipOp to quiesce the SBE
     *
     * @param[in]  i_target  Target with SBE to quiesce
     *
     * @return errlHndl_t Error log handle on failure.
     *
     */
    errlHndl_t sendPsuQuiesceSbe(TARGETING::Target * i_target)
    {
        errlHndl_t errl = NULL;

        SBE_TRACD(ENTER_MRK "sending psu quiesce command from HB -> SBE");

        // set up PSU command message
        SbePsu::psuCommand   l_psuCommand(
                                  SbePsu::SBE_REQUIRE_RESPONSE,  //control flags
                                  SbePsu::SBE_PSU_GENERIC_MESSAGE, //command class
                                  SbePsu::SBE_PSU_GENERIC_MSG_QUIESCE); //command
        SbePsu::psuResponse  l_psuResponse;


        errl =  SBEIO::SbePsu::getTheInstance().performPsuChipOp(i_target,
                                &l_psuCommand,
                                &l_psuResponse,
                                SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                                SbePsu::SBE_QUIESCE_REQ_USED_REGS,
                                SbePsu::SBE_QUIESCE_RSP_USED_REGS);

        SBE_TRACD(EXIT_MRK "sendPsuQuiesceSbe");

        return errl;
    };

} //end namespace SBEIO

