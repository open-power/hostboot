/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/runtime/rt_service.C $                          */
/*                                                                        */
/* IBM CONFIDENTIAL                                                       */
/*                                                                        */
/* COPYRIGHT International Business Machines Corp. 2013                   */
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
#include "../service.H"
#include "../compdesc.H"
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <runtime/interface.h>

namespace TRACE
{

    Service::Service()
    {
    }

    Service::~Service()
    {
        // No need to destruct the service.
        assert(0);
    }

    void Service::writeEntry(ComponentDesc* i_td,
                             trace_hash_val i_hash,
                             const char * i_fmt,
                             uint32_t i_line,
                             uint32_t i_type,
                             va_list i_args)
    {
        if (unlikely(i_type == TRACE_DEBUG))
        {
            if (!i_td->iv_debugEnabled)
            {
                return;
            }
        }

        char output[KILOBYTE];
        vsprintf(output, i_fmt, i_args); // TODO: RTC 79420 :
                                         // Potential buffer overrun.
        g_hostInterfaces->puts(output);
    }

    void Service::writeBinEntry(ComponentDesc* i_td,
                                trace_hash_val i_hash,
                                uint32_t i_ine,
                                const void* i_ptr,
                                uint32_t i_size,
                                uint32_t i_type)
    {
        if (unlikely(i_type == TRACE_DEBUG))
        {
            if (!i_td->iv_debugEnabled)
            {
                return;
            }
        }

        // TODO: RTC 79420

    }

    size_t Service::getBuffer(ComponentDesc* i_comp,
                              void * o_data,
                              size_t i_size)
    {
        // No way to get the buffer back in runtime.
        return 0;
    }

    void Service::flushBuffers()
    {
        // No-op in runtime.
    }

}
