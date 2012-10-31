/* IBM_PROLOG_BEGIN_TAG                                                   */
/* This is an automatically generated prolog.                             */
/*                                                                        */
/* $Source: src/usr/trace/interface.C $                                   */
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

#include "compdesc.H"
#include "service.H"

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

        (*o_td) =
            Singleton<ComponentList>::instance().getDescriptor(i_comp,
                                                               i_size,
                                                               i_bufferType);
    }

    void trace_adal_write_all(ComponentDesc * io_td,
                              const trace_hash_val i_hash,
                              const char * i_fmt,
                              const uint32_t i_line,
                              const int32_t i_type, ...)
    {
        va_list args;
        va_start(args, i_type);

        Singleton<Service>::instance().writeEntry(io_td, i_hash, i_fmt,
                                                  i_line, i_type, args);

        va_end(args);
    }

    void trace_adal_write_bin(ComponentDesc * io_td,
                              const trace_hash_val i_hash,
                              const uint32_t i_line,
                              const void * i_ptr,
                              const uint32_t i_size,
                              const int32_t i_type)
    {
        Singleton<Service>::instance().writeBinEntry(io_td, i_hash, i_line,
                                                     i_ptr, i_size, i_type);
    }

    size_t getBuffer(const char * i_comp,
                       void * o_data,
                       size_t i_bufferSize )
    {
        ComponentDesc* l_comp =
            Singleton<ComponentList>::instance().getDescriptor(i_comp, 0);

        if (NULL == l_comp)
        {
            return 0;
        }
        return Singleton<Service>::instance().getBuffer(l_comp,
                                                        o_data, i_bufferSize);
    }

    void flushBuffers()
    {
        Singleton<Service>::instance().flushBuffers();
    }
};
