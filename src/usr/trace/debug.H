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
        // Continuous Trace:
            /** Override of attribute setting.
             *    0 - Use attribute (default).
             *    1 - Force Disable
             *    2 - Force Enable
             */
        uint8_t contTraceOverride;
            /** Size of continuous trace buffer. */
        uint16_t bufferSize;
            /** Pointer to continuous trace buffer. */
        void* bufferPage;
    };

    extern DebugSettings g_debugSettings;
}

#endif
