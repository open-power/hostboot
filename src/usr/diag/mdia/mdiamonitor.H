/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/mdiamonitor.H $                             */
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
         * @brief ctor
         */
        CommandMonitor();

        /**
         * @brief dtor
         */
        virtual ~CommandMonitor();

    protected:

        /**
         * @brief serialization mutex
         */
        mutex_t iv_mutex;

        /**
         * @brief shutdown request indicator
         */
        bool iv_shutdown;

        /**
         * @brief aliases. Map containing monitorID key and timeout entries.
         */
        typedef std::map<uint64_t, uint64_t> MonitorMap;
        typedef MonitorMap::iterator monitorMapIterator;

        /**
         * @brief maint command monitors
         */
        MonitorMap iv_monitors;

    private:

        /**
         * @brief main thread function
         */
        static void* staticMain(void *);

        /**
         * @brief main thread function
         *
         * @param[in] i_sm state machine provided for callback
         */
        virtual void threadMain(StateMachine & i_sm);

        /**
         * @brief Get MonitorMap Timeout entry
         *
         * @param[in] i_monitor Monitor ID
         *
         * @retval Timeout value associated with monitor ID i_monitor
         */
        uint64_t getMonitorMapTimeoutEntry(uint64_t i_monitor);

        /**
         * @brief thread number
         */
        tid_t iv_tid;

        /**
         * @brief monitor ID counter
         */
        uint64_t iv_nextMonitor;

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
