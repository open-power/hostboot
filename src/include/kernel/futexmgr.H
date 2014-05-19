/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/futexmgr.H $                               */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2011,2014              */
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
#ifndef FUTEXMGR
#define FUTEXMGR

/**
 * @file futexmgr.H
 * @brief Declaration for kernel side futex management
 */

#include <stdint.h>
#include <util/locked/list.H>
#include <kernel/spinlock.H>

struct task_t;


/**
 * @class FutexManager
 * Kernel internal management of fuxtexs
 */
class FutexManager
{
    public:

        /**
         * Put the current processes on a wait queue
         * @param[in] i_task  pointer to the current task structure
         * @param[in] i_addr  Futex address 
         * @param[in] i_val   Value that *i_addr should contain
         * @returns [0 | error code]  if *i_addr != i_val returns EWOULDBLOCK
         */
        static uint64_t wait(task_t * i_task, uint64_t * i_addr, uint64_t i_val);

        /**
         * Wakeup and optionally move waiting processes.
         * @param[in] i_futex1 pointer to a futex
         * @param[in] i_count1 The max number of tasks to wake
         * @param[in] i_futex2 pointer to a futex, (default NULL) Optional
         *                     futex to move i_count_2 unwoken tasks to.
         * @param[in] i_count2 The max number of theads to move from futex1 to 
         *                     futex2. (default 0)
         *
         * @returns The number of tasks awoken
         */
        static uint64_t wake(uint64_t * i_futex1, uint64_t i_count1,
                             uint64_t * i_futex2 = NULL, uint64_t i_count2 = 0);

    protected:

        /**
         * Ctor
         */
        FutexManager() {};

        /**
         * Dtor
         */
        ~FutexManager() {};

    private: // functions

        /** see wait(...) */
        uint64_t _wait(task_t * i_task, uint64_t * i_addr, uint64_t i_val);

        /** see wake(...) */
        uint64_t _wake(uint64_t * i_futex1, uint64_t i_count1,
                       uint64_t * i_futex2, uint64_t i_count2);

    private: // data

        struct _FutexWait_t
        {
            _FutexWait_t * next;    ///< next _FutexWait_t in list
            _FutexWait_t * prev;    ///< prev _FutexWait_t in list
            uint64_t * key;         ///< search key is futex address
            task_t* task;           ///< task on wait list
        };

        typedef Util::Locked::List<_FutexWait_t, uint64_t *> FutexList_t;

        Spinlock iv_lock;       ///< lock
        FutexList_t iv_list;    ///< List of waiting tasks for all futexes
};

#endif

