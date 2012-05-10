//  IBM_PROLOG_BEGIN_TAG
//  This is an automatically generated prolog.
//
//  $Source: src/usr/diag/mdia/mdiamonitor.H $
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
#ifndef __MSS_MEMDIAG_MDIAMONITOR_H
#define __MSS_MEMDIAG_MDIAMONITOR_H

#include <map>
#include <sys/sync.h>
#include <sys/task.h>
#include <stdint.h>
#include "mdiafwd.H"

/**
 * @file mdiamonitor.H
 * @brief mdia Maintenance Command Monitor
 */

namespace MDIA
{

/**
 * @brief maint command timeout monitor
 *
 * provides an interface for the workflow state machine
 * to register / unregister for a monitor and receive a callback
 * if the monitor times out.  when the state machine callback is
 * made the monitor is automatically removed
 */
class CommandMonitor
{
    public:
        /**
         * @brief add a new monitor with specified timeout value
         *
         * @param[in] i_to Maint Cmd timeout value
         *
         * @retval Monitor ID
         */
        uint64_t addMonitor(uint64_t i_to);

        /**
         * @brief remove a monitor
         *
         * @param[in] i_monitor MonitorMap's key, monitor ID
         */
        void removeMonitor(uint64_t i_monitor);

        /**
         * @brief start the thread up, specify callback
         *
         * @param[in] i_sm state machine to which call is made
         */
        void start(StateMachine & i_sm);

        /**
         * @brief shut the thread down
         */
        void shutdown();

        /**
         * @brief start polling for a maint command complete event
         *
         * @param[in] i_target the target to poll
         */
        void startPolling(TARGETING::TargetHandle_t i_target);

        /**
         * @brief ctor
         */
        CommandMonitor();

        /**
         * @brief dtor
         */
        ~CommandMonitor();

    private:

        /**
         * @brief main thread function
         */
        static void staticMain(void *);

        /**
         * @brief main thread function
         *
         * @param[in] i_sm state machine provided for callback
         */
        void threadMain(StateMachine & i_sm);

        /**
         * @brief Get the thread id
         *
         * @retval ThreadID of CommandMonitor
         */
        tid_t getTID();

        /**
         * @brief Is the CommandMonitor shut down
         *
         * @retval true if shutdown
         *         false if not shutdown
         */
        bool isShutdown();

        /**
         * @brief Get the monitor id counter
         *
         * @retval Monitor ID counter
         */
        uint64_t getMonitorID();

        /**
         * @brief Get MonitorMap Timeout entry
         *
         * @param[in] i_monitor Monitor ID
         *
         * @retval Timeout value associated with monitor ID i_monitor
         */
        uint64_t getMonitorMapTimeoutEntry(uint64_t i_monitor);

        /**
         * @brief serialization mutex
         */
        mutex_t iv_mutex;

        /**
         * @brief thread number
         */
        tid_t iv_tid;

        /**
         * @brief shutdown request indicator
         */
        bool iv_shutdown;

        /**
         * @brief monitor ID counter
         */
        uint64_t iv_nextMonitor;

        /**
         * @brief aliases. Map containing monitorID key and timeout entries.
         */
        typedef std::map<uint64_t, uint64_t> MonitorMap;
        typedef MonitorMap::iterator monitorMapIterator;

        /**
         * @brief maint command monitors
         */
        MonitorMap iv_monitors;

        /**
         * @brief list of targets to do polling
         */
        TARGETING::TargetHandleList iv_pollingList;

        /**
         * @brief copy disabled
         */
        CommandMonitor(const CommandMonitor &);

        /**
         * @brief assignment disabled
         */
        CommandMonitor & operator=(const CommandMonitor &);

        /**
         * @brief friend class
         */
        friend class ::MdiaCommandMonitorTest;
};
}
#endif
