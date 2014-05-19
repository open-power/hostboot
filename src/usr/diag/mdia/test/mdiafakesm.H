/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/diag/mdia/test/mdiafakesm.H $                         */
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
#ifndef __TEST_MDIAFAKESM_H
#define __TEST_MDIAFAKESM_H

#include "../mdiasm.H"
#include "../mdiamonitor.H"
#include "../mdiafwd.H"

namespace MDIA
{
/**
 * @brief FakeStateMachine1
 *
 * Used to test processing a maint command timeout
 * from the CommandMonitor perspective
 */
class FakeStateMachine1 : public StateMachine
{
    public:
        /**
         * @brief processCommandTimeout
         *
         * Verifies if the vector of monitorIDs(i_monitorIDs) passed in
         * is the expected vector of timed out monitorIDs(iv_monitors)
         *
         * @param[in] i_monitorIDs Vector of monitorIDs that have timed out
         */
        void processCommandTimeout(const std::vector<uint64_t> & i_monitorIDs);

        /**
         * @brief addMonitor
         *
         * Add a monitor to the vector of iv_monitors
         *
         * @param[in] i_mon Monitor ID of target
         */
        void addMonitor(uint64_t i_mon);

        /**
         * @brief removeMonitor
         *
         * Removes the monitor at position 'i_position' from iv_monitors
         *
         * @param[in] i_position Position of monitor ID in vector iv_monitors
         */
        void removeMonitor(const uint64_t i_position);

        /**
         * @brief isTimeoutProcessed
         *
         * Is the timeout processed
         *
         * @retval true if processed
         *         false is not processed
         */
        bool isTimeoutProcessed() const;

        /**
         * @brief isContentsEqual
         *
         * Are the contents of vector of monitorIDs sent from
         * CommandMonitor equal to the expected value
         *
         * @retval true if equal
         *         false if not equal
         */
        bool isContentsEqual() const;

        /**
         * @brief setTotalExpectedMons
         *
         * Sets the expected number of monitor IDs that timeout
         *
         * @param[in] i_count Total number of expected timeouts
         */
        void setTotalExpectedMons(const uint64_t i_count);

        /**
         * @brief setSyncVars
         *
         * Sets the sync variables to be in-sync with the unit test
         *
         * @param[in] i_mutex Serialization Mutex
         * @param[in] i_cond  Synchronization condition
         */
        void setSyncVars(mutex_t *i_mutex, sync_cond_t *i_cond);

        /**
         * @brief ctor
         */
        FakeStateMachine1();

        /**
         * @brief dtor
         */
        ~FakeStateMachine1(){}

    private:
        /**
         * @brief isEqual
         *
         * Compares two sets of vectors of monitorIDs
         *
         * @param[in] i_monitorIDs Vector of monitorIDs
         */
        bool isEqual(const std::vector<uint64_t> & i_monitorIDs) const;

        /**
         * @brief Processed timeout indicator
         */
        bool iv_processedTimeout;

        /**
         * @brief Contents of expected and real timeouts equality indicator
         */
        bool iv_contentsEqual;

        /**
         * @brief Vector of expected monitor IDs to timeout
         */
        std::vector<uint64_t> iv_expectedMonitors;

        /**
         * @brief Expected number to monitor IDs to timeout
         */
        uint64_t iv_totalExpectedMons;

        /**
         * @brief Processed timeout condition
         */
        sync_cond_t *iv_cond;

        /**
         * @brief serialization mutex
         */
        mutex_t *iv_mutex;
};
}
#endif
