/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/usr/diag/mdia/mdia.H $                            */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2021                        */
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
 * @brief MaintCommandEventType - maint command event types
 */
enum MaintCommandEventType
{
    /** The command reached the end of the address range. */
    COMMAND_COMPLETE,

    /** A fault is found during analysis and no further testing is needed. */
    STOP_TESTING,

    /** PRD detected an error and needs time to complete analysis. */
    RESET_TIMER,

    /** The channel has failed and no further testing is needed */
    CHNL_FAILED,
};

/**
 * @brief MaintCommandEvent maint command event
 */
struct MaintCommandEvent
{
    /**
     * @brief type the type associated with the event
     */
    MaintCommandEventType type;

    /**
     * @brief target the target associated with the event
     */
    TARGETING::TargetHandle_t target;
};

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
