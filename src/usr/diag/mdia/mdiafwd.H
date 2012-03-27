//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiafwd.H $
//
//  IBM CONFIDENTIAL
//
//  COPYRIGHT International Business Machines Corp. 2012
//
//  p1
//
//  Object Code Only (OCO) source materials
//  Licensed Internal Code Source Materials
//  IBM HostBoot Licensed Internal Code
//
//  The source code for this program is not published or other-
//  wise divested of its trade secrets, irrespective of what has
//  been deposited with the U.S. Copyright Office.
//
//  Origin: 30
//
//  IBM_PROLOG_END
#ifndef __MDIA_MDIAFWD_H
#define __MDIA_MDIAFWD_H

/**
 * @file mdiafwd.H
 * @brief internal mdia declarations
 */

#include <mdia/mdia.H>
#include <targeting/common/attributes.H>
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
 * @brief work flow phases
 */
enum WorkFlowPhase
{
    RESTORE_DRAM_REPAIRS,
    START_PATTERN_0,
    START_PATTERN_1,
    START_PATTERN_2,
    START_PATTERN_3,
    START_PATTERN_4,
    START_PATTERN_5,
    START_PATTERN_6,
    START_PATTERN_7,
    START_PATTERN_8,
    START_SCRUB,
    DUMMY_SYNC_PHASE,
    DUMMY_ASYNC_PHASE,
};

/**
 * @brief per mba diagnostic mode
 */
enum DiagMode
{
    INIT_ONLY,
    SCRUB_ONLY,
    ONE_PATTERN,
    FOUR_PATTERNS,
    NINE_PATTERNS,
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
typedef std::vector<WorkFlowPhase> WorkFlow;

/**
* @brief WorkflowAssocMap target / workflow association map
*/
typedef std::map<TARGETING::TargetHandle_t, WorkFlow> WorkFlowAssocMap;

/**
* @brief WorkflowAssoc target / workflow association list element
*/
typedef WorkFlowAssocMap::const_iterator WorkFlowAssoc;

/**
 * @brief getMbaDiagnosticMode get the mode (scrub, init, one, four, nine)
 *
 * @param[in] i_globals policy flags needed to determine the mode
 * @param[in] i_target the mba target for which the mode is determined
 * @param[out] o_mode the mode for the target mba
 *
 * @retval 0 no error
 * @retval !0 unexpected error occurred
 */
errlHndl_t getMbaDiagnosticMode(
        const Globals & i_globals,
        TARGETING::TargetHandle_t i_mba,
        DiagMode & o_mode);

/**
 * @brief getMbaWorkFlow get the workflow for an mba target
 *
 * @param[in] i_mode the diagnostic mode for the target
 * @param[out] o_wf the workflow for the mba target
 *
 * @retval 0 no error
 * @retval !0 unexpected error occurred
 */
errlHndl_t getMbaWorkFlow(
        DiagMode i_mode,
        WorkFlow & o_wf);

/**
 * @brief doStepCleanup shut down threads and pools on step exit
 *
 * @param[in] i_globals contains objects to be cleaned up
 */
void doStepCleanup(const Globals & i_globals);

}
#endif
