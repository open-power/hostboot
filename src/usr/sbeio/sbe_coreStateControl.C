/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_coreStateControl.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2016                        */
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
 * @file sbe_coreStateControl.C
 * @brief Core State Control Messages to control the deadmap loop
 */

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include "sbe_psudd.H"

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"coreStateControl: " printf_string,##args)

namespace SBEIO
{

/**
 * @brief Start Deadman loop
 *
 * @param[in] i_waitTime Time to wait in milliseconds
 *
 * @return errlHndl_t Error log handle on failure.
 *
 */

errlHndl_t startDeadmanLoop(const uint64_t i_waitTime )
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "startDeadmanLoop waitTime=0x%x",i_waitTime);

    psuCommand   l_psuCommand(
         SBE_DMCONTROL_START | SBE_DMCONTROL_RESPONSE_REQUIRED, //control flags
         SBE_PSU_CLASS_CORE_STATE,                              //command class
         SBE_CMD_CONTROL_DEADMAN_LOOP);                         //comand
    psuResponse  l_psuResponse;

    // set up PSU command message
    l_psuCommand.cdl_waitTime = i_waitTime;

    errl = performPsuChipOp(&l_psuCommand,
                            &l_psuResponse,
                            MAX_PSU_SHORT_TIMEOUT_NS,
                            SBE_DMCONTROL_START_REQ_USED_REGS,
                            SBE_DMCONTROL_START_RSP_USED_REGS);

    SBE_TRACD(EXIT_MRK "startDeadmanLoop");

    return errl;
};



/**
 * @brief Stop Deadman loop
 *
 * @return errlHndl_t Error log handle on failure.
 *
 */
errlHndl_t stopDeadmanLoop()
{
    errlHndl_t errl = NULL;

    SBE_TRACD(ENTER_MRK "stopDeadmanLoop");

    psuCommand   l_psuCommand(
         SBE_DMCONTROL_STOP + SBE_DMCONTROL_RESPONSE_REQUIRED, //control flags
         SBE_PSU_CLASS_CORE_STATE,                             //command class
         SBE_CMD_CONTROL_DEADMAN_LOOP);                        //comand
    psuResponse  l_psuResponse;

    errl = performPsuChipOp(&l_psuCommand,
                            &l_psuResponse,
                            MAX_PSU_SHORT_TIMEOUT_NS,
                            SBE_DMCONTROL_STOP_REQ_USED_REGS,
                            SBE_DMCONTROL_STOP_RSP_USED_REGS);

    SBE_TRACD(EXIT_MRK "stopDeadmanLoop");

    return errl;
};
} //end namespace SBEIO

