/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/mdia/mdia.H $                            */
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
#ifndef __MDIA_MDIA_H
#define __MDIA_MDIA_H

#include <errl/errlentry.H>
#include <targeting/common/target.H>

/**
 * @file mdia.H
 * @brief mdia component interface
 */

namespace MDIA
{
struct MaintCommandEvent;

/**
 * @brief MaintCommandEventType - maint command event types
 */
enum MaintCommandEventType
{
    /**
     * @brief COMMAND_COMPLETE - command finished at end of last rank
     */
    COMMAND_COMPLETE,

    /**
     * @brief COMMAND_STOPPED - command finished at end of other rank
     */
    COMMAND_STOPPED,

    /**
     * @brief SKIP_MBA - stop testing mba
     */
    SKIP_MBA,

    /**
     * @brief RESET_TIMER - command done but expect long analysis
     */
    RESET_TIMER,
};

/**
 * @brief runStep istep dispatcher entry point.
 *
 * execute the memory diagnostics ipl step on a single mba
 * or a list of mbas
 *
 * @param[in] i_targetList the targets on which to run diagnostics
 *
 * @return errlHndl_t. Error log handle.
 * @retval 0 no errors
 * @retval !0 error occurred
 *
 * @pre memory ready to hold data, node free of attentions
 * @post memory tested and initialized, ready to hold data
 */
errlHndl_t runStep(const TARGETING::TargetHandleList & i_targetList);

/**
 * @brief waitingForMaintCmdEvents
 *
 * Provides an indicator of whether or not memory
 * diagnostics is running and waiting for
 * calls to the processEvent function.
 *
 * @param[out] o_waiting indicator.
 */
void waitingForMaintCmdEvents(bool & o_waiting);

/**
 * @brief processEvent prd callback
 *
 * called by prd to inform memory diagnostics of attention
 * related events like maint command complete or hw error.
 *
 * @param[in] i_event prd attention event to be processed
 *
 * @return errlHndl_t. Error log handle.
 * @retval 0 no errors
 * @retval !0 error occurred
 *
 * @pre memory diagnostics ipl step in progress
 * @post message processed
 */
errlHndl_t processEvent(MaintCommandEvent & i_event);
}
#endif
