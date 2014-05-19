/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/include/kernel/idebug.H $                                 */
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
#ifndef __KERNEL_IDEBUG_H
#define __KERNEL_IDEBUG_H

/** @file idebug.H
 *  @brief Structure for interactive debug support.
 */

#include <kernel/types.h>
#include <kernel/taskmgr.H>

/** @class InteractiveDebug
 *  @brief Structure that defines data needed for an interactive-debug call.
 */
class InteractiveDebug
{
    public:
        /** Union to contain the state information between the kernel and
         *  the debug tool.
         */
        union
        {
            struct
            {
                    /** Boolean for 'ready' state. */
                uint8_t ready;
                    /** Boolean to mark kernel running request. */
                uint8_t running;
                    /** Boolean to mark execution is complete. */
                uint8_t complete;
                uint8_t __reserved[5];
            };
                /** Word so that state can be atomically updated. */
            uint64_t state_value;
        };

            /** Address of the desired function's TOC. */
        uint64_t entry_point_toc;
            /** Return value from function. */
        uint64_t return_value;

            /** Desired function parameters. */
        uint64_t parms[8];

        /** @brief Returns the 'ready' state from the union. */
        bool isReady() { return ready != 0; };

        /** @brief Creates a userspace task to execute debug call.
         *
         *  @pre 'ready' state set and entry_point/parms are initialized by
         *       the debug tool.
         *
         *  @post A detached task is created to execute the function.
         */
        void startDebugTask();

    private:
        /** @brief Entry point for 'task_create' of debug task.
         *  @param[in] idebug - Pointer to this interactive-debug structure.
         */
        static void* debugEntryPoint(void* idebug);
};

#endif
