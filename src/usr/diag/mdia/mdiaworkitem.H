/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiaworkitem.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
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
         * @param[in] i_chipUnit mba position (0/1)
         */
        WorkItem(StateMachine & i_sm, WorkFlowProperties * i_wfp,
                uint64_t i_priority, uint8_t i_chipUnit);

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
         * @brief the mba number on the membuf (0/1)
         */
        uint8_t iv_chipUnit;

        /**
         * @brief copy disabled
         */
        WorkItem(const WorkItem &);

        /**
         * @brief assignment disabled
         */
        WorkItem & operator=(const WorkItem &);

        /**
         * @brief provide internal access to unit test
         */
        friend class ::MdiaWorkItemTest;
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
