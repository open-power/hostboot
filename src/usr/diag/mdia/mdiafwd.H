/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiafwd.H $                                 */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2020                        */
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
#ifndef __MDIA_MDIAFWD_H
#define __MDIA_MDIAFWD_H

/**
 * @file mdiafwd.H
 * @brief internal mdia declarations
 */

#include <mdia/mdia.H>
#include <mdia/mdiareasoncodes.H>
#include <targeting/common/attributes.H>
#include <targeting/common/targetservice.H>
#include <vector>
#include <map>

/**
 * @brief forwards
 */
class MdiaSmTest;
class MdiaTest;
class MdiaMbaTest;
class MdiaCommandMonitorTest;
class MdiaTraceTest;
class MdiaWorkItemTest;

namespace MDIA
{

/**
 * forwards
 */
class StateMachine;
class WorkItem;
class CommandMonitor;
struct Globals;
struct WorkFlowProperties;

/**
 * @brief per mba diagnostic mode
 */
enum DiagMode
{
    ONE_PATTERN,
    FOUR_PATTERNS,
    NINE_PATTERNS,
};

/**
 * @brief misc constants
 */
enum
{

    // mcc dstlfir unit regs
    DSTLFIR                 = 0x0C010D00,
    DSTLFIR_MASK            = 0x0C010D03,
    DSTLFIR_ACT0            = 0x0C010D06,
    DSTLFIR_ACT1            = 0x0C010D07,
    DSTLCFG2                = 0x0C010D0E,

    // ocmb mcbist unit regs
    OCMB_MCBIST_FIR         = 0x08011800,
    OCMB_MCBIST_FIR_AND     = 0x08011801,
    OCMB_MCBIST_FIR_MASK    = 0x08011803,
    OCMB_MCBIST_FIR_ACT0    = 0x08011806,
    OCMB_MCBIST_FIR_ACT1    = 0x08011807,

    // ocmb omidlfir unit regs
    OMIDLFIR                = 0x08012800,
    OMIDLFIR_MASK           = 0x08012803,
    OMIDLFIR_ACT0           = 0x08012806,
    OMIDLFIR_ACT1           = 0x08012807,

    // proc regs
    IPOLL_MASK              = 0x000F0033,
    IPOLL_STATUS            = 0x000F0034,
    GLOBAL_CS_FIR           = 0x570F001C,
    GLOBAL_RE_FIR           = 0x570F001B,
    GLOBAL_UCS_FIR          = 0x570F002A,
    GLOBAL_HA_FIR           = 0x570F002B,

    // mc chiplet registers
    MC0_CHIPLET_HA_FIR      = 0x0C040004,
    MC0_CHIPLET_HA_FIR_MASK = 0x0C040044,
    MC1_CHIPLET_HA_FIR      = 0x0D040004,
    MC1_CHIPLET_HA_FIR_MASK = 0x0D040044,
    MC2_CHIPLET_HA_FIR      = 0x0E040004,
    MC2_CHIPLET_HA_FIR_MASK = 0x0E040044,
    MC3_CHIPLET_HA_FIR      = 0x0F040004,
    MC3_CHIPLET_HA_FIR_MASK = 0x0F040044,
};

/**
 * @brief workflow status
 */
enum WorkFlowStatus
{
    /**
     * @brief workflow in progress or hasn't started yet
     */
    IN_PROGRESS,

    /**
     * @brief indicates workflow stopped because a maint command timed out
     */
    COMMAND_TIMED_OUT,

    /**
     * @brief indicates workflow stopped because of a failure
     */
    FAILED,

    /**
     * @brief workflow finished
     */
    COMPLETE,
};

/**
* @brief Workflow container of workflow phases
*/
typedef std::vector<uint64_t> WorkFlow;

/**
* @brief WorkflowAssocMap target / workflow association map
*/
typedef std::map<TARGETING::TargetHandle_t, WorkFlow> WorkFlowAssocMap;

/**
* @brief WorkflowAssoc target / workflow association list element
*/
typedef WorkFlowAssocMap::const_iterator WorkFlowAssoc;

/**
* @brief MonitorIDs container of monitorIDs unique to a target
*/
typedef std::vector<uint64_t> MonitorIDs;

/**
 * @brief getDiagnosticMode get the mode (scrub, init, one, four, nine)
 *
 * @param[in] i_globals policy flags needed to determine the mode
 * @param[in] i_target the mba/mcbist target for which the mode is determined
 * @param[out] o_mode the mode for the target mba/mcbist
 *
 * @retval 0 no error
 * @retval !0 unexpected error occurred
 */
errlHndl_t getDiagnosticMode(
        const Globals & i_globals,
        TARGETING::TargetHandle_t i_trgt,
        DiagMode & o_mode);

/**
 * @brief getWorkFlow get the workflow for an mba/mcbist target
 *
 * @param[in] i_mode the diagnostic mode for the target
 * @param[out] o_wf the workflow for the mba/mcbist target
 * @param[in] i_globals policy flags needed to determine MNFG status
 *
 * @retval 0 no error
 * @retval !0 unexpected error occurred
 */
errlHndl_t getWorkFlow(
        DiagMode i_mode,
        WorkFlow & o_wf,
        const Globals & i_globals);

/**
 * @brief doStepCleanup shut down threads and pools on step exit
 *
 * @param[in] i_globals contains objects to be cleaned up
 *
 * @return nullptr on success; non-nullptr on error
 */
errlHndl_t doStepCleanup(const Globals & i_globals);

/**
 * @brief check if hw state has been changed for an mba
 *        or mcbist's associated targets
 *
 * @param[in] i_trgt input mba/mcbist target
 *
 * @retval true if hw state has been changed or else
 */
bool isHWStateChanged(TARGETING::TargetHandle_t i_trgt);

/**
 * @brief clear hw changed state for an mba
 *        or mcbist's associated targets
 *
 * @param[in] i_trgt input mba/mcbist target
 *
 */
void clearHWStateChanged(TARGETING::TargetHandle_t i_trgt);

}
#endif
