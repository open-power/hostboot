//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiasmimpl.H $
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
#ifndef __MDIA_MDIASMIMPL_H
#define __MDIA_MDIASMIMPL_H

/**
 * @file mdiasmimpl.H
 * @brief mdia state machine implementation
 */

#include <algorithm>
#include "mdiafwd.H"

namespace MDIA
{

/**
 * @brief workFlow properties
 *
 * associate a workflow progress indicator (workItem), log
 * and status indicator with a workflow and target
 */
struct WorkFlowProperties
{
    /**
     * @brief pointer to target / workFlow association
     */
    WorkFlowAssoc assoc;

    /**
     * @brief the workFlow phase to be run next
     */
    WorkFlow::const_iterator workItem;

    /**
     * @brief workFlow status indicator
     */
    uint64_t status;

    /**
     * @brief log associated with the workFlow
     */
    errlHndl_t log;

    /**
     * @brief timer associated with the workFlow
     */
    uint64_t timer;

    /**
     * @brief maint command flag associated with the workFlow
     */
    bool restartCommand;

    /**
     * @brief memory size associated with the workFlow
     */
    uint64_t memSize;
};

/**
 * @brief getWorkFlow alias for pair::second
 *
 * @param[in] i_assoc the WorkFlowAssocMap element from which to get
 * the workflow
 *
 * @retval reference to the workflow in the WorkFlowAssocMap
 *
 */
ALWAYS_INLINE inline const WorkFlow & getWorkFlow(WorkFlowAssoc i_assoc)
{
    return i_assoc->second;
}

/**
 * @brief getWorkFlow alias for pair::second
 *
 * @param[in] i_wfp the WorkFlowProperties from which to get
 * the workflow
 *
 * @retval reference to the workflow in the WorkFlowProperties
 *
 */
ALWAYS_INLINE inline const WorkFlow & getWorkFlow(WorkFlowProperties & i_wfp)
{
    return i_wfp.assoc->second;
}

/**
 * @brief getTarget alias for pair::first
 *
 * @param[in] i_wfp the WorkFlowProperties from which to get
 * the target
 *
 * @retval target handle in the WorkFlowAssocMap
 */
ALWAYS_INLINE inline TARGETING::TargetHandle_t getTarget(WorkFlowAssoc i_assoc)
{
    return i_assoc->first;
}

/**
 * @brief getTarget alias for pair::first
 *
 * @param[in] i_wfp the WorkFlowProperties from which to get
 * the target
 *
 * @retval target handle in the WorkFlowProperties
 */
ALWAYS_INLINE inline TARGETING::TargetHandle_t getTarget(WorkFlowProperties & i_wfp)
{
    return i_wfp.assoc->first;
}

/**
 * @brief getRemainingWorkItems
 *
 * determine the number of remaining work items for a given workflow
 *
 * @param[in] i_wfp the WorkFlowProperties from which to get
 * the workflow
 *
 * @retval number of remaining work items
 */
ALWAYS_INLINE inline uint64_t getRemainingWorkItems(WorkFlowProperties & i_wfp)
{
    return std::distance(i_wfp.workItem, getWorkFlow(i_wfp).end());
}
}
#endif
