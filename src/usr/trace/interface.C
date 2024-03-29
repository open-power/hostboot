/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/interface.C $                                   */
/*                                                                        */
/* OpenPOWER HostBoot Project                                             */
/*                                                                        */
/* Contributors Listed Below - COPYRIGHT 2012,2023                        */
/* [+] International Business Machines Corp.                              */
/*                                                                        */
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

/** @file interface.C
 *  @brief Implementation of the trace interfaces.
 *
 *  Most of the functions in this file are simply redirections to the
 *  appropriate class/instance that handles this functionality.
 */

#include <trace/interface.H>
#include <util/singleton.H>
#include <stdarg.h>
#include <limits.h>
#include <string.h>

#include "compdesc.H"
#include "service.H"

#if  __HOSTBOOT_RUNTIME
#include "runtime/rt_rsvdtracebufservice.H"
#endif

namespace TRACE
{
    TracInit::TracInit(trace_desc_t** o_td,
                       const char * i_comp,
                       const size_t i_size,
                       uint8_t i_bufferType)
    {
        initBuffer(o_td, i_comp, i_size, i_bufferType);
    }

    TracInit::~TracInit() {}



    void initBuffer(ComponentDesc** o_td,
                    const char* i_comp,
                    size_t i_size,
                    uint8_t i_bufferType)
    {

        if (i_size == 0)
        {
            i_size = KILOBYTE;
        }

#ifdef __HOSTBOOT_RUNTIME
        // Run all Runtime traces to same buffer
        i_bufferType = BUFFER_FAST;
#endif
        (*o_td) =
            Singleton<ComponentList>::instance().getDescriptor(i_comp,
                                                               i_size,
                                                               i_bufferType);
    }

    void trace_adal_write_all(ComponentDesc * io_td,
                              const traceCodeInfo* i_info,
                              const uint32_t i_line,
                              const uint32_t i_type, ...)
    {
        va_list args;
        va_start(args, i_type);

        Singleton<Service>::instance().writeEntry(io_td,
                                                  i_info->hash, i_info->format,
                                                  i_line, i_type, args);

        va_end(args);
    }

    void trace_adal_write_bin(ComponentDesc * io_td,
                              const traceCodeInfo* i_info,
                              const uint32_t i_line,
                              const void * i_ptr,
                              const uint32_t i_size,
                              const uint32_t i_type)
    {
        Singleton<Service>::instance().writeBinEntry(io_td, i_info->hash,
                                                     i_info->format, i_line,
                                                     i_ptr, i_size, i_type);
    }

    size_t getBuffer(const char * i_comp,
                       void * o_data,
                       size_t i_bufferSize )
    {
        size_t l_bufferSize(0);

        ComponentDesc* l_comp =
            Singleton<ComponentList>::instance().getDescriptor(i_comp, 0);

        if (NULL == l_comp)
        {
#if  __HOSTBOOT_RUNTIME
            // All the components will have a corresponding CompDescriptor,
            // if buffer is created. RSVD_MEM_TRACE is a speacial case without
            // a corresponding compDescriptor. Check for RSVD_MEM_TRACE, if
            // not RSVD_MEM_TRACE then return 0.
            if(strcmp( i_comp, "RSVD_MEM_TRACE") == 0)
            {
                l_bufferSize =  Singleton<RsvdTraceBufService>::
                                     instance().getBuffer(o_data,i_bufferSize);
            }
#endif
        }
        else
        {
            l_bufferSize = Singleton<Service>::instance().getBuffer(l_comp,
                                                        o_data, i_bufferSize);
        }
        return l_bufferSize;
    }

    void flushBuffers()
    {
        Singleton<Service>::instance().flushBuffers();
    }

#ifndef __HOSTBOOT_RUNTIME
    void enableContinousTrace()
    {
        Singleton<Service>::instance().enableContinous();
    }

    void disableContinousTrace()
    {
        Singleton<Service>::instance().disableContinous();
    }
#endif

    bool isDebugEnabled(ComponentDesc * i_td)
    {
        return i_td->isDebugEnabled();
    }

    void enableDebug(const char* i_comp,
                     bool i_enable)
    {
        ComponentDesc* l_comp =
            Singleton<ComponentList>::instance().getDescriptor(i_comp, 0);
        l_comp->enableDebug(i_enable);
    }

};
