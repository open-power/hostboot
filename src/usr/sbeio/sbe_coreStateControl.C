/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_coreStateControl.C $                        */
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
 * @file sbe_coreStateControl.C
 * @brief Core State Control Messages to control the deadmap loop
 */

#include <config.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"coreStateControl: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"coreStateControl: " printf_string,##args)

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

    // Find master proc for target of PSU command
    TARGETING::Target * l_master = nullptr;
    (void)TARGETING::targetService().masterProcChipTargetHandle(l_master);

    SbePsu::psuCommand   l_psuCommand(
         SbePsu::SBE_DMCONTROL_START |
             SbePsu::SBE_DMCONTROL_RESPONSE_REQUIRED,      //control flags
         SbePsu::SBE_PSU_CLASS_CORE_STATE,                 //command class
         SbePsu::SBE_CMD_CONTROL_DEADMAN_LOOP);            //command
    SbePsu::psuResponse  l_psuResponse;

    // set up PSU command message
    l_psuCommand.cd1_ControlDeadmanLoop_WaitTime = i_waitTime;

    errl = SBEIO::SbePsu::getTheInstance().performPsuChipOp(l_master,
                            &l_psuCommand,
                            &l_psuResponse,
                            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                            SbePsu::SBE_DMCONTROL_START_REQ_USED_REGS,
                            SbePsu::SBE_DMCONTROL_START_RSP_USED_REGS);

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

    // Find master proc for target of PSU command
    TARGETING::Target * l_master = nullptr;
    (void)TARGETING::targetService().masterProcChipTargetHandle(l_master);

    SbePsu::psuCommand   l_psuCommand(
         SbePsu::SBE_DMCONTROL_STOP +
             SbePsu::SBE_DMCONTROL_RESPONSE_REQUIRED,        //control flags
         SbePsu::SBE_PSU_CLASS_CORE_STATE,                   //command class
         SbePsu::SBE_CMD_CONTROL_DEADMAN_LOOP);              //comand
    SbePsu::psuResponse  l_psuResponse;

    errl = SBEIO::SbePsu::getTheInstance().performPsuChipOp(l_master,
                            &l_psuCommand,
                            &l_psuResponse,
                            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                            SbePsu::SBE_DMCONTROL_STOP_REQ_USED_REGS,
                            SbePsu::SBE_DMCONTROL_STOP_RSP_USED_REGS);

    SBE_TRACD(EXIT_MRK "stopDeadmanLoop");

    return errl;
};
} //end namespace SBEIO

