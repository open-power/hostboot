/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/debug.H $                                       */
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
#ifndef __TRACE_DEBUG_H
#define __TRACE_DEBUG_H

#include <stdint.h>

namespace TRACE
{
    /** @struct DebugSettings
     *
     *  Settings and values used by the debug tools to interact with the
     *  trace component.
     */
    struct DebugSettings
    {
        enum
        {
            /** Use attribute (default). */
            CONT_TRACE_USE_ATTR = 0,
            /** Force disable. */
            CONT_TRACE_FORCE_DISABLE = 1,
            /** Force enable. */
            CONT_TRACE_FORCE_ENABLE = 2,
        };

        // Continuous Trace:
        uint8_t contTraceOverride;
        /** Global switch for debug trace (TRACS). */
        bool globalDebugEnable;
            /** Size of continuous trace buffer. */
        uint16_t bufferSize;
            /** Pointer to continuous trace buffer. */
        void* bufferPage;

    };

    extern DebugSettings g_debugSettings;
}

#endif
