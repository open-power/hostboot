/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/debug.H $                                       */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2012                   */
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
