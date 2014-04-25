/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiasm.H $                                  */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012,2014              */
/*                                                                        */
/* p1                                                                     */
/*                                                                        */
/* Object Code Only (OCO) source materials                                */
/* Licensed Internal Code Source Materials                                */
/* IBM HostBoot Licensed Internal Code                                    */
/*                                                                        */
/* The source code for this program is not published or otherwise         */
/* divested of its trade secrets, irrespective of what has been           */
/* deposited with the U.S. Copyright Office.                              */
/*                                                                        */
/* Origin: 30                                                             */
/*                                                                        */
/* IBM_PROLOG_END_TAG                                                     */
#ifndef __MDIA_MDIASM_H
#define __MDIA_MDIASM_H

/**
 * @file mdiasm.H
 * @brief mdia state machine definition
 */

#include <vector>
#include <util/threadpool.H>
#include <utility_procedures/mss_maint_cmds.H>
#include "sys/sync.h"
#include "mdiafwd.H"
#include "mdiaglobals.H"

namespace MDIA
{

//MBA timeout value - 30 secs
static const uint64_t MBA_TIMEOUT = 30000000000;

//MBA timeout count max before timing out (~3 min)
//TODO: RTC: 106213 enhance memdiags timeout detection
static const uint64_t MBA_TIMEOUTCNT_MAX = 6;

/**
 * @brief work flow phases
 */
enum WorkFlowPhase
{
    START_PATTERN_0 = mss_MaintCmd::PATTERN_0,
    START_PATTERN_1 = mss_MaintCmd::PATTERN_1,
    START_PATTERN_2 = mss_MaintCmd::PATTERN_2,
    START_PATTERN_3 = mss_MaintCmd::PATTERN_3,
    START_PATTERN_4 = mss_MaintCmd::PATTERN_4,
    START_PATTERN_5 = mss_MaintCmd::PATTERN_5,
    START_PATTERN_6 = mss_MaintCmd::PATTERN_6,
    START_PATTERN_7 = mss_MaintCmd::PATTERN_7,
    START_RANDOM_PATTERN,
    DUMMY_SYNC_PHASE,
    DUMMY_ASYNC_PHASE,
    RESTORE_DRAM_REPAIRS,
    START_SCRUB,
    CLEAR_HW_CHANGED_STATE,
    ANALYZE_IPL_MNFG_CE_STATS,
};

/**
 * @brief memory diagnostics step state machine
 */
class StateMachine
{
    public:

        /**
         * @brief running State machine in progress indicator.
         *
         * @param[out] o_running In progress indicator.
         */
        void running(bool & o_running);

        /**
         * @brief used by Maint cmd monitor to notify that
         * maint cmd timed out - called in monitor thread context
         *
         * @param[in] i_monitorIDs Vector of monitorIDs
         */
        virtual void processCommandTimeout(
                        const MonitorIDs & i_monitorIDs);

        /**
         * @brief run the state machine to completion
         *
         * @param[in] i_list array of target / workFlow associations
         *
         * @retval 0 no errors
         * @retval !0 error occurred
         */
        errlHndl_t run(const WorkFlowAssocMap & i_list);

        /**
         * @brief shutdown state machine
         */
        void shutdown();

        /**
         * @brief processMaintCommandEvent process maint command event from prd
         *
         * @param[in] i_event the event to be processed
         *
         * @retval true a work item was dispatched
         * @retval false a work item was not dispatched
         */
        bool processMaintCommandEvent(const MaintCommandEvent & i_event);

        /**
         * @brief ctor
         */
        StateMachine();

        /**
         * @brief dtor
         */
        virtual ~StateMachine();

        /**
         * @brief set global params
         *
         * @param[in] i_globals global data
         */
        void setGlobals(Globals & i_globals);

    protected:

        /**
         * @brief serialization mutex
         */
        mutex_t iv_mutex;

        /**
         * @brief command monitor
         */
        CommandMonitor * iv_monitor;

    private:

        /**
         * @brief aliases
         */
        typedef std::vector<WorkFlowProperties *> WorkFlowPropertiesList;
        typedef std::vector<WorkFlowProperties *>::iterator
                WorkFlowPropertiesIterator;

        /**
         * @brief setup load the workflow properties for the provided
         * target / workflow association(s)
         *
         * @param[in] i_list target / workflow association(s) for which
         * to load the workflow properties
         */
        void setup(const WorkFlowAssocMap & i_list);

        /**
         * @brief start start the machine thread pool and start
         * dispatching work items
         */
        void start();

        /**
         * @brief wait wait for a started state machine to run to
         * completion
         */
        void wait();

        /**
         * @brief reset internal state
         */
        void reset();

        /**
         * @brief workItemIsAsync test the workflow properties
         * for an async work item
         *
         * @param[in] i_wfp the workflow properties to test for async
         *
         * @retval false work item is synch
         * @retval true work item is async
         */
        static bool workItemIsAsync(WorkFlowProperties & i_wfp);

        /**
         * @brief allWorkFlowsComplete check to see if all workflows are
         * finished
         *
         * @retval true all work flows are finished
         * @retval false all work flows are not finished
         */
        bool allWorkFlowsComplete();

        /**
         * @brief scheduleWorkItem
         *
         * @param[in] i_wfp the target for which a work item should be scheduled
         *
         * @retval true work item was dispatched
         * @retval false work item was not dispatched
         */
        bool scheduleWorkItem(WorkFlowProperties & i_wfp);

        /**
         * @brief doMaintCommand maint command work item handler
         *
         * determine the correct command and issue it
         *
         * @param[in] i_wfp the target for which a command should be issued
         */
        virtual errlHndl_t doMaintCommand(WorkFlowProperties & i_wfp);

        /**
         * @brief executeWorkItem work item entry point for
         * pool threads
         *
         * @param[in] i_wfp the work item to be executed
         *
         * @retval true next work item was dispatched
         * @retval false next work item was not dispatched
         */
        bool executeWorkItem(WorkFlowProperties * i_wfp);

        /**
         * @brief create and start command monitor if not
         * done already
         *
         * @retval command monitor reference
         */
        CommandMonitor & getMonitor();

        /**
         * @brief workFlow properties
         */
        WorkFlowPropertiesList iv_workFlowProperties;

        /**
         * @brief overall status condition
         */
        bool iv_done;

        /**
         * @brief shutdown indicator
         */
        bool iv_shutdown;

        /**
         * @brief thread pool
         */
        Util::ThreadPool<WorkItem> * iv_tp;

        /**
         * @brief completion condition
         */
        sync_cond_t iv_cond;

        /**
         * @brief global struct
         */
        Globals iv_globals;

        /**
         * @brief copy disabled
         */
        StateMachine(const StateMachine &);

        /**
         * @brief assignment disabled
         */
        StateMachine & operator=(const StateMachine &);

        /**
         * @brief provide internal access to unit test
         */
        friend class ::MdiaSmTest;

        /**
         * @brief provide internal access to WorkItem
         */
        friend class WorkItem;
};
}
#endif
