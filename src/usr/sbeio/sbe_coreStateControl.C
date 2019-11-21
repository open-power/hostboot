/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/sbeio/sbe_coreStateControl.C $                        */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2019                        */
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

#include <errno.h>
#include <sys/mm.h>
#include <trace/interface.H>
#include <errl/errlmanager.H>
#include <sbeio/sbeioif.H>
#include <sbeio/sbe_psudd.H>
#include <sbeio/sbeioreasoncodes.H>
#include <targeting/common/targetservice.H>

extern trace_desc_t* g_trac_sbeio;

#define SBE_TRACD(printf_string,args...) \
    TRACDCOMP(g_trac_sbeio,"coreStateControl: " printf_string,##args)

#define SBE_TRACF(printf_string,args...) \
    TRACFCOMP(g_trac_sbeio,"coreStateControl: " printf_string,##args)

namespace
{

/* This variable is used by startDeadmanLoop and stopDeadmanLoop to track the
 * allocation of SCOM address/value pairs that the SBE will execute once
 * Hostboot enters a sleep state.
 *
 * Stores a pointer to the allocation after startDeadmanLoop is called, and the
 * allocation is freed by stopDeadmanLoop. */
SBEIO::sbeAllocationHandle_t scomRegInitAllocation { };

} // end anonymous namespace

namespace SBEIO
{

errlHndl_t startDeadmanLoop(
    const uint64_t i_waitTime,
    const std::pair<uint64_t, uint64_t>* const i_regInits,
    const size_t i_regInitCount
)
{
    errlHndl_t errl = nullptr;

    SBE_TRACD(ENTER_MRK "startDeadmanLoop waitTime=0x%x",i_waitTime);

    do {

    /* If someone calls this function twice in a row without calling
     * stopDeadmanLoop in between, the global variable will already be set (and
     * we will have nowhere to store the allocation), so signal an error.. */
    if (scomRegInitAllocation)
    {
        /*@
         * @errortype    ERRL_SEV_UNRECOVERABLE
         * @moduleid     SBEIO_DEAD_MAN_TIMER
         * @reasoncode   SBEIO_START_DMT_CALLED_TWICE
         * @devdesc      startDeadmanLoop was called twice in a row
         * @custdesc     Logic error in failsafe timer start/stop
         */
        errl = new ERRORLOG::ErrlEntry(ERRORLOG::ERRL_SEV_UNRECOVERABLE,
                                       SBEIO_DEAD_MAN_TIMER,
                                       SBEIO_START_DMT_CALLED_TWICE,
                                       0, 0,
                                       ERRORLOG::ErrlEntry::ADD_SW_CALLOUT);
        break;
    }

    // Find master proc for target of PSU command
    TARGETING::Target * l_master = nullptr;
    (void)TARGETING::targetService().masterProcChipTargetHandle(l_master);

    SbePsu::psuCommand   l_psuCommand(
         SbePsu::SBE_DMCONTROL_START |
             SbePsu::SBE_DMCONTROL_RESPONSE_REQUIRED,      //control flags
         SbePsu::SBE_PSU_CLASS_CORE_STATE,                 //command class
         SbePsu::SBE_CMD_CONTROL_DEADMAN_LOOP);            //command

    SbePsu::psuResponse  l_psuResponse;

    uint64_t l_alignedRegInitsPhysAddr = 0;

    // We don't have to allocate any memory for register inits when there are no
    // writes for the SBE to perform
    if (i_regInitCount)
    {
        void* l_sbeMemAlloc = nullptr;

        scomRegInitAllocation = sbeMalloc(sizeof(*i_regInits) * i_regInitCount,
                                          l_sbeMemAlloc);

        const auto l_alignedRegInits
            = static_cast<std::pair<uint64_t, uint64_t>*>(l_sbeMemAlloc);

        std::copy(i_regInits, i_regInits + i_regInitCount, l_alignedRegInits);

        // SBE consumes a physical address. NOTE: We assume that the virtual
        // pages returned by malloc() are backed by contiguous physical pages.
        l_alignedRegInitsPhysAddr = mm_virt_to_phys(l_alignedRegInits);

        assert(static_cast<int>(l_alignedRegInitsPhysAddr) != -EFAULT,
               "startDeadmanLoop: mm_virt_to_phys failed");
    }

    // set up PSU command message
    l_psuCommand.cd1_ControlDeadmanLoop_WaitTime = i_waitTime;
    l_psuCommand.cd1_ControlDeadmanLoop_ScomRegInitsAddr = l_alignedRegInitsPhysAddr;
    l_psuCommand.cd1_ControlDeadmanLoop_ScomRegInitsCount = i_regInitCount;

    errl = SBEIO::SbePsu::getTheInstance().performPsuChipOp(l_master,
                            &l_psuCommand,
                            &l_psuResponse,
                            SbePsu::MAX_PSU_SHORT_TIMEOUT_NS,
                            SbePsu::SBE_DMCONTROL_START_REQ_USED_REGS,
                            SbePsu::SBE_DMCONTROL_START_RSP_USED_REGS);

    } while (0);

    SBE_TRACD(EXIT_MRK "startDeadmanLoop");

    return errl;
};

errlHndl_t stopDeadmanLoop()
{
    errlHndl_t errl = nullptr;

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

    sbeFree(scomRegInitAllocation);

    SBE_TRACD(EXIT_MRK "stopDeadmanLoop");

    return errl;
};

} // end namespace SBEIO
