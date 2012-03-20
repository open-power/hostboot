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
#include <targeting/target.H>

/**
 * @brief forwards
 */
class MdiaCommandMonitorTest;

namespace MDIA
{

class StateMachine;
class WorkItem;

/**
 * @brief work flow phases
 */
enum WorkFlowPhase
{
    POPULATE_MBA_PROPERTIES,
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
    PROCESS_ATTENTION,
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
}
#endif
