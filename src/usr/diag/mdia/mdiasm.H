//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiasm.H $
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
#ifndef __MDIA_MDIASM_H
#define __MDIA_MDIASM_H

/**
 * @file mdiasm.H
 * @brief mdia state machine definition
 */

#include "mdiafwd.H"

namespace MDIA
{

/**
 * @brief memory diagnostics step state machine
 */
class StateMachine
{
    public:

        /**
         * @brief work item entry point for threadpool
         *
         * @param[in] i_target work item target
         * @param[in] i_phase work item phase
         */
        void executeWorkItem(TARGETING::TargetHandle_t i_target, WorkFlowPhase i_phase) {}

        /**
         * @brief used by Maint cmd monitor to notify that
         * maint cmd timed out - called in monitor thread context
         *
         * @param[in] i_monitorIDs Vector of monitorIDs
         */
        virtual void processCommandTimeout(std::vector<uint64_t> i_monitorIDs) {}

        /**
         * @brief ctor
         */
        StateMachine() {}

        /**
         * @brief dtor
         */
        virtual ~StateMachine() {}

    private:

        /**
         * @brief copy disabled
         */
        StateMachine(const StateMachine &);

        /**
         * @brief assignment disabled
         */
        StateMachine & operator=(const StateMachine &);
};
}
#endif
