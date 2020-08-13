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
    // mem chiplet regs
    MEM_SPA_FIR             = 0x03040004,
    MEM_SPA_FIR_MASK        = 0x03040007,
    MEM_MBA0_MBSTR          = 0x02011655,
    MEM_MBA1_MBSTR          = 0x02011755,

    // mba unit regs
    MBA01_SPA               = 0X03010611,
    MBA01_SPA_MASK          = 0X03010614,
    MBA01_CMD_TYPE          = 0X0301060A,
    MBA01_CMD_CONTROL       = 0X0301060B,
    MBA01_CMD_STATUS        = 0X0301060C,
    MBA01_MBMACAQ           = 0X0301060D,
    MBA01_MBMEA             = 0X0301060E,

    // mcbist unit regs
    MCBIST_FIR              = 0x07012300,
    MCBIST_FIR_AND          = 0x07012301,
    MCBIST_FIR_MASK         = 0x07012303,
    MCBIST_FIR_ACT0         = 0x07012306,
    MCBIST_FIR_ACT1         = 0x07012307,

    // mcc dstlfir unit regs
    DSTLFIR                 = 0x07010900,
    DSTLFIR_MASK            = 0x07010903,
    DSTLFIR_ACT0            = 0x07010906,
    DSTLFIR_ACT1            = 0x07010907,
    DSTLCFG2                = 0x0701090E,

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

    // mcs unit regs
    CHI_FIR                 = 0x07010900,
    CHI_FIR_MASK            = 0x07010903,
    CHI_FIR_ACT0            = 0x07010906,
    CHI_FIR_ACT1            = 0x07010907,

    // proc regs
    IPOLL_MASK              = 0x000F0033,
    IPOLL_STATUS            = 0x000F0034,
    GLOBAL_CS_FIR           = 0x500F001C,
    GLOBAL_RE_FIR           = 0x500F001B,
    GLOBAL_UCS_FIR          = 0x50040018,
    GLOBAL_HA_FIR           = 0x50040009,

    // mc chiplet registers
    MC0_CHIPLET_HA_FIR      = 0x07040009,
    MC0_CHIPLET_HA_FIR_MASK = 0x0704001a,
    MC1_CHIPLET_HA_FIR      = 0x08040009,
    MC1_CHIPLET_HA_FIR_MASK = 0x0804001a,
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
