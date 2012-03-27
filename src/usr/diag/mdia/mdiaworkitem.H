//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiaworkitem.H $
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
#ifndef __MDIA_MDIAWORKITEM_H
#define __MDIA_MDIAWORKITEM_H

/**
 * @file mdiaworkitem.H
 * @brief threadpool workitem definition
 */

#include <stdint.h>
#include "mdiafwd.H"

namespace MDIA
{

/**
 * @brief mdia work item
 */
class WorkItem
{
    public:

        /**
         * @brief task function, called by threadpool
         */
        void operator()();

        /**
         * @brief work item comparison
         * @param[in] i_rhs external work item to compare to
         *
         * @retval -1 this < i_rhs
         * @retval 1 i_rhs < this
         * @retval 0 i_rhs !< this && this !< i_rhs
         */
        int64_t compare(const WorkItem & i_rhs) const;

        /**
         * @brief ctor
         *
         * work items with higher i_priority are executed before
         * work items with lower i_priority
         *
         * @param[in] i_sm state machine to forward call to
         * @param[in] i_wfp state machine state snapshot
         * @param[in] i_priority work item priority
         */
        WorkItem(StateMachine & i_sm, WorkFlowProperties * i_wfp,
                uint64_t i_priority);

    private:

        /**
         * @brief state machine reference
         */
        StateMachine & iv_sm;

        /**
         * @brief state machine state to be passed back to the state machine
         */
        WorkFlowProperties * iv_wfp;

        /**
         * @brief the scheduling priority for the work item
         */
        uint64_t iv_priority;

        /**
         * @brief copy disabled
         */
        WorkItem(const WorkItem &);

        /**
         * @brief assignment disabled
         */
        WorkItem & operator=(const WorkItem &);
};

/**
 * @brief comparison operator
 * @param[in] i_l left hand side
 * @param[in] i_r right hand side
 */
inline bool operator<(const WorkItem & i_l, const WorkItem & i_r)
{
    return i_l.compare(i_r) < 0;
}
}
#endif
